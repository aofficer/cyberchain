<?php

/**
 * Abstract class with generic implementation of most service methods.
 */
class SearchApiMongoDBService extends SearchApiAbstractService {

  /**
   * @var SearchApiServer
   */
  protected $server;

  /**
   * Direct reference to the server's $options property.
   *
   * @var array
   */
  protected $options = array();

  /**
   * Constructor for a service class, setting the server configuration used with
   * this service.
   *
   * @param SearchApiServer $server
   *   The server object for this service.
   */
  public function __construct(SearchApiServer $server) {
    $this->server = $server;
    $this->options = &$server->options;

    $connection_name = !empty($this->options['connection']) ? $this->options['connection'] : 'default';
    $collection_name = !empty($this->options['collection']) ? $this->options['collection'] : 'drupal_search_api';

    $this->mongodb = mongodb($connection_name);
    $this->collection = mongodb_collection(array($collection_name, ''));
  }

  /**
   * Form callback. Might be called on an uninitialized object - in this case,
   * the form is for configuring a newly created server.
   *
   * Returns an empty form by default.
   *
   * @return array
   *   A form array for setting service-specific options.
   */
  public function configurationForm(array $form, array &$form_state) {
    $form = array();

    $connections = array_keys(variable_get('mongodb_connections', array('default' => array('host' => 'localhost', 'db' => 'default'))));

    $form['connection'] = array(
      '#title' => t('Connection Info'),
      '#type' => 'select',
      '#options' => $connections,
      '#default_value' => $this->options['connection']
    );

    $collections = array_keys(variable_get('mongodb_collections', array('default' => array('default'))));

    $form['collection'] = array(
      '#title' => t('Collection Info'),
      '#type' => 'select',
      '#options' => $collections,
      '#default_value' => $this->options['collection']
    );

    $form['min_chars'] = array(
      '#type' => 'select',
      '#title' => t('Minimum word length'),
      '#description' => t('The minimum number of characters a word must consist of to be indexed.'),
      '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6)),
      '#default_value' => 1,
    );

    return $form;
  }

  /**
   * Validation callback for the form returned by configurationForm().
   *
   * Does nothing by default.
   *
   * @param array $form
   *   The form returned by configurationForm().
   * @param array $values
   *   The part of the $form_state['values'] array corresponding to this form.
   * @param array $form_state
   *   The complete form state.
   */
  public function configurationFormValidate(array $form, array &$values, array &$form_state) {
    return;
  }

  /**
   * Submit callback for the form returned by configurationForm().
   *
   * The default implementation just ensures that additional elements in
   * $options, not present in the form, don't get lost at the update.
   *
   * @param array $form
   *   The form returned by configurationForm().
   * @param array $values
   *   The part of the $form_state['values'] array corresponding to this form.
   * @param array $form_state
   *   The complete form state.
   */
  public function configurationFormSubmit(array $form, array &$values, array &$form_state) {
    if (!empty($this->options)) {
      $values += $this->options;
    }
    $this->options = $values;

    // Set up indexing
    $this->collection->ensureIndex(array('keywords.word' => 1));
    drupal_set_message(t('MongoDB collection and index created.'));
  }

  /**
   * Determines whether this service class implementation supports a given
   * feature. Features are optional extensions to Search API functionality and
   * usually defined and used by third-party modules.
   * Currently, the only feature specified directly in the search_api project is
   * "search_api_facets", defined by the module of the same name.
   *
   * @param string $feature
   *   The name of the optional feature.
   *
   * @return boolean
   *   TRUE if this service knows and supports the specified feature. FALSE
   *   otherwise.
   */
  public function supportsFeature($feature) {
    return FALSE;
  }

  /**
   * View this server's settings. Output can be HTML or a render array, a <dl>
   * listing all relevant settings is preferred.
   *
   * The default implementation does a crude output as a definition list, with
   * option names taken from the configuration form.
   */
  public function viewSettings() {
    $output = '';
    $form = $form_state = array();
    $option_form = $this->configurationForm($form, $form_state);
    $option_names = array();
    foreach ($option_form as $key => $element) {
      if (isset($element['#title']) && isset($this->options[$key])) {
        $option_names[$key] = $element['#title'];
      }
    }

    foreach ($option_names as $key => $name) {
      $value = $this->options[$key];
      $output .= '<dt>' . check_plain($name) . '</dt>' . "\n";
      $output .= '<dd>' . nl2br(check_plain(print_r($value, TRUE))) . '</dd>' . "\n";
    }

    return $output ? "<dl>\n$output</dl>" : '';
  }

  /**
   * Called once, when the server is first created. Allows it to set up its
   * necessary infrastructure.
   *
   * Does nothing, by default.
   */
  public function postCreate() {
    return;
  }

  /**
   * Notifies this server that its fields are about to be updated. Fields set on
   * this object will still show the old values to allow comparison.
   *
   * Does nothing, by default.
   *
   * @param array $fields
   *   The fields that are about to change, mapped to their values.
   *
   * @return
   *   TRUE, if the update requires reindexing of all content on the server.
   */
  public function postUpdate() {
    return FALSE;
  }

  /**
   * Notifies this server that it has been re-enabled and allows the object to
   * react appropriately.
   *
   * Does nothing, by default.
   */
  public function postEnable() {
    return;
  }

  /**
   * Notifies this server that it is about to be deleted from the database and
   * should therefore clean up, if appropriate.
   *
   * By default, deletes all indexes from this server.
   */
  public function preDelete() {
    $indexes = entity_load('search_api_index', FALSE, array('server' => $this->server->machine_name));
    foreach ($indexes as $index) {
      $this->removeIndex($index);
    }
  }

  /**
   * Add a new index to this server.
   *
   * Does nothing, by default.
   *
   * @param SearchApiIndex $index
   *   The index to add.
   */
  public function addIndex(SearchApiIndex $index) {
    return;
  }

  /**
   * Notify the server that the indexed field settings for the index have
   * changed.
   * If any user action is necessary as a result of this, the method should
   * use drupal_set_message() to notify the user.
   *
   * @param SearchApiIndex $index
   *   The updated index.
   *
   * @return
   *   TRUE, if this change affected the server in any way that forces it to
   *   re-index the content. FALSE otherwise.
   */
  public function fieldsUpdated(SearchApiIndex $index) {
    return FALSE;
  }

  /**
   * Remove an index from this server.
   *
   * This might mean that the index has been deleted, or reassigned to a
   * different server. If you need to distinguish between these cases, inspect
   * $index->server.
   *
   * By default, removes all items from that index.
   *
   * @param $index
   *   Either an object representing the index to remove, or its machine name
   *   (if the index was completely deleted).
   */
  public function removeIndex($index) {
    $this->deleteItems('all', $index);
  }

  /**
   * Create a query object for searching on an index lying on this server.
   *
   * @param SearchApiIndex $index
   *   The index to search on.
   * @param $options
   *   Associative array of options configuring this query. See
   *   SearchApiQueryInterface::__construct().
   *
   * @throws SearchApiException
   *   If the server is currently disabled.
   *
   * @return SearchApiQueryInterface
   *   An object for searching the given index.
   */
  public function query(SearchApiIndex $index, $options = array()) {
    return new SearchApiQuery($index, $options);
  }

  protected function keywordJson($keys) {
    // Here we construct a JSON string to compare whether
    // or not the indexed keyword is in the search keys array.
    $keys_json_array = '';
    if (is_array($keys)) {
      foreach ($keys as &$key) {
        $keys_json_array[$key] = ''; 
        $key = drupal_strtolower($key); 
      }
    }
    else {
      $key_string = $keys;
      $keys_json_array[$keys] = ''; 
      $keys = array($key_string);
    }

    return json_encode($keys_json_array);
  }

  /**
   * Executes a search on the server represented by this object.
   *
   * @param $query
   *   The SearchApiQueryInterface object to execute.
   *
   * @throws SearchApiException
   *   If an error prevented the search from completing.
   *
   * @return array
   *   An associative array containing the search results, as required by
   *   SearchApiQueryInterface::execute().
   */
  public function search(SearchApiQueryInterface $api_query) {
    $time_method_called = microtime(TRUE);
    $keys = &$api_query->getKeys();
    $keys_set = (boolean) $keys;
    $keys = $this->prepareKeys($keys);
    $results = array();
    $options = $api_query->getOptions();

    if (is_array($keys)) {
      $conjunction = $keys['#conjunction'];
      unset($keys['#conjunction']);
    }
    else {
      $conjunction = 'AND';
    }

    switch ($conjunction) {
      case 'AND':
        $conj_op = '$all';
        break;
      default:
        $conj_op = '$in';
        break;
    }

    $filter = $api_query->getFilter();
    $query = array();
    if ($filter->getFilters()) {
      $keys = array();
      foreach ($filter->getFilters() as $f) {
        $f_keys = $this->prepareKeys($f[1]);
        if (is_scalar($f_keys)) {
          $f_key_string = $f_keys;
          $f_keys = array($f_key_string);
        }
        $keys = array_merge($keys, $f_keys);
//@todo This really needs to be an $and (if there was such a thing) - how do we get that to work in php?
        $query['$or'][] = array(
          'keywords.word' => array($conj_op => $f_keys),
          'keywords.field' => $f[0],
        );
      }
    }
    else {
      if (is_scalar($keys)) {
        $key_string = $keys;
        $keys = array($key_string);
      }
      if ($keys_set && !empty($keys[0])) {
        $query['keywords.word'] = array($conj_op => $keys);
      }
    }

    $keys_json = $this->keywordJson($keys);

    $connection_name = !empty($this->options['connection']) ? $this->options['connection'] : 'default';
    $collection_name = !empty($this->options['collection']) ? $this->options['collection'] : 'drupal_search_api';

    // MapReduce aggregation. Basically we emit the entire list of
    // keywords for the collection entry and compare against the
    // search keys to determine the score.
    $map = new MongoCode("function() { emit(this.item_id, this.keywords); }");
    $reduce = new MongoCode("function(k, vals) { "
    .'var score = 0;'
    .'for (var i = 0; i < vals[0].length; i++) {'
      .'if (vals[0][i].word in ' . $keys_json . ') {'
        .'score += vals[0][i].score;'
      .'}'
    .'}'
    .'return {"score":score};'
    .'}');

  
    $search = $this->mongodb->command(
      array(
        'mapreduce' => $collection_name,
        'map' => $map,
        'reduce' => $reduce,
        'query' => $query
      )
    );

    if (isset($search['result'])) {
      $cursor = $this->mongodb->selectCollection($search['result'])->find()
        ->sort(array('value.score' => -1))
        ->skip($options['offset'])
        ->limit($options['limit']);
    }

    $time_processing_done = microtime(TRUE);

    if (isset($cursor)) {
      $result_count = $cursor->count();
      while ($cursor->hasNext()) {
        $result = $cursor->getNext();
        $results['results'][$result['_id']] = array(
          'id' => $result['_id'],
          'score' => $result['value']['score'],
        );
      }
    }
    else {
      $result_count = 0;
    }

    $time_queries_done = microtime(TRUE);
    $time_end = microtime(TRUE);

    $results['performance'] = array(
      'complete' => $time_end - $time_method_called,
      // @todo calculate performance
      //'preprocessing' => $time_processing_done - $time_method_called,
      //'execution' => $time_queries_done - $time_processing_done,
      //'postprocessing' => $time_end - $time_queries_done,
    );
    $results['result count'] = $result_count;

    return $results;
  }


  /**
   * Index the specified items.
   *
   * @param SearchApiIndex $index
   *   The search index for which items should be indexed.
   * @param array $items
   *   An array of items to be indexed, keyed by their id. The values are
   *   associative arrays of the fields to be stored, where each field is an
   *   array with the following keys:
   *   - type: One of the data types recognized by the Search API, or the
   *     special type "tokens" for fulltext fields.
   *   - original_type: The original type of the property as defined through a
   *     hook_entity_property_info().
   *   - value: The value to index.
   *
   *   The special field "search_api_language" contains the item's language and
   *   should always be indexed.
   *
   *   The value of fields with the "tokens" type is an array of tokens. Each
   *   token is an array containing the following keys:
   *   - value: The word that the token represents.
   *   - score: A score for the importance of that word.
   *
   * @throws SearchApiException
   *   If indexing was prevented by a fundamental configuration error.
   *
   * @return array
   *   An array of the ids of all items that were successfully indexed.
   */
  public function indexItems(SearchApiIndex $index, array $items) {
    // @todo need exception handling.
    $return = array();
    foreach ($items as $id => $item) {
      $this->indexItem($index, $id, $item);

      $indexed[] = $id;
    }
    return $indexed;
  }

  protected function indexItem(SearchApiIndex $index, $id, array $item) {
    $item_id = $id;
    $index_id = $index->id;
    $keywords = array();

    // @todo do we need to be responsible for cron limit?
    foreach ($item as $name => $field) {
      $boost = $field['boost'];

      // @todo double check this removal
      $this->collection->remove(array('item_id' => $item_id));

      $type = $field['type'];
      $value = $this->convert($field['value'], $type, $field['original_type']);

      if (search_api_is_text_type($type, array('text', 'tokens'))) {
        $words = array();
        foreach ($value as $token) {
          // Taken from core search to reflect less importance of words later in the text.
          // Focus is a decaying value in terms of the amount of unique words up to this point.
          // From 100 words and more, it decays, to e.g. 0.5 at 500 words and 0.3 at 1000 words.
          $focus = min(1, .01 + 3.5 / (2 + count($words) * .015));

          $value = &$token['value'];
          if (is_numeric($value)) {
            $value = ltrim($value, '-0');
          }
          elseif (drupal_strlen($value) < $this->options['min_chars']) {
            continue;
          }
          $value = drupal_strtolower($value);
          $token['score'] *= $focus;
          if (!isset($words[$value])) {
            $words[$value] = $token;
          }
          else {
            $words[$value]['score'] += $token['score'];
          }
        }
        if ($words) {
          foreach ($words as $word) {
            $add = array(
              'word' => $word['value'],
              'score' => $word['score'],
              'field' => $name,
            );
            if (!in_array($add, $keywords)) {
              $keywords[] = $add;
            }
          }
        }
      }
      elseif (search_api_is_list_type($type)) {
        $values = array();
        if (is_array($value)) {
          foreach ($value as $v) {
            if ($v !== NULL) {
              $values[$v] = TRUE;
            }
          }
          $values = array_keys($values);
        }
        else {
          $values[] = $value;
        }
        if ($values) {
          foreach ($values as $word) {
            $add = array(
              'word' => $word['value'],
              'field' => $name,
            );
            if (!in_array($add, $keywords)) {
              $keywords[] = $add;
            }
          }
        }
      }
      else {
        $add = array(
          'word' => $value,
          'field' => $name,
        );
        if (!in_array($add, $keywords)) {
          $keywords[] = $add;
        }
      }
    }

    if ($keywords) {
      $this->collection->save(array(
        'item_id' => $item_id, 
        'index_id' => $index_id, 
        'entity_type' => $index->entity_type, 
        'keywords' => $keywords
      ));
    }

    return TRUE;
  }

  /**
   * Delete items from an index on this server.
   *
   * Might be either used to delete some items (given by their ids) from a
   * specified index, or all items from that index, or all items from all
   * indexes on this server.
   *
   * @param $ids
   *   Either an array containing the ids of the items that should be deleted,
   *   or 'all' if all items should be deleted. Other formats might be
   *   recognized by implementing classes, but these are not standardized.
   * @param SearchApiIndex $index
   *   The index from which items should be deleted, or NULL if all indexes on
   *   this server should be cleared (then, $ids has to be 'all').
   */
  public function deleteItems($ids = 'all', SearchApiIndex $index = NULL) {
    if ($ids == 'all') {
      $this->collection->remove();
    }
    else {
      foreach($ids as $id) {
        $query = array('item_id' => $id, 'index_id' => $index->id);
        $this->collection->remove($query);
      }
    }
  }

  protected function convert($value, $type, $original_type) {
    if (search_api_is_list_type($type)) {
      $type = substr($type, 5, -1);
      $original_type = search_api_extract_inner_type($original_type);
      $ret = array();
      foreach ($value as $v) {
        $v = $this->convert($v, $type, $original_type);
        $ret = array_merge($ret, is_array($v) ? $v : array($v));
      }
      return $ret;
    }
    switch ($type) {
      case 'text':
        $ret = array();
        foreach (preg_split('/[^\p{L}\p{N}]+/u', $value, -1, PREG_SPLIT_NO_EMPTY) as $v) {
          if ($v) {
            $ret[] = array(
              'value' => $v,
              'score' => 1.0,
            );
          }
        }
        return $ret;

      case 'tokens':
        return $value;

      case 'string':
      case 'uri':
        // For non-dates, PHP can handle this well enough
        if ($original_type == 'date') {
          return date('%c', $value);
        }
        return $value;

      case 'integer':
      case 'duration':
      case 'decimal':
        return 0 + $value;

      case 'boolean':
        return $value ? 1 : 0;

      case 'date':
        if (is_numeric($value) || !$value) {
          return 0 + $value;
        }
        return strtotime($value);

      default:
        throw new SearchApiException(t('Unknown field type !type. Database search module might be out of sync with Search API.', array('!type' => $type)));
    }
  }

  /**
   * Helper method for removing unnecessary nested expressions from keys.
   */
  protected function prepareKeys($keys) {
    if (is_scalar($keys)) {
      $keys = $this->splitKeys($keys);
      return is_array($keys) ? $this->eliminateDuplicates($keys) : $keys;
    }
    elseif (!$keys) {
      return NULL;
    }
    $keys = $this->eliminateDuplicates($this->splitKeys($keys));
    $conj = $keys['#conjunction'];
    $neg = !empty($keys['#negation']);
    foreach ($keys as $i => &$nested) {
      if (is_array($nested)) {
        $nested = $this->prepareKeys($nested);
        if ($neg == !empty($nested['#negation'])) {
          if ($nested['#conjunction'] == $conj) {
            unset($nested['#conjunction'], $nested['#negation']);
            foreach ($nested as $renested) {
              $keys[] = $renested;
            }
            unset($keys[$i]);
          }
        }
      }
    }
    $keys = array_filter($keys);
    if (($count = count($keys)) <= 2) {
      if ($count < 2 || isset($keys['#negation'])) {
        $keys = NULL;
      }
      else {
        unset($keys['#conjunction']);
        $keys = array_shift($keys);
      }
    }
    return $keys;
  }

  /**
   * Helper method for splitting keys.
   */
  protected function splitKeys($keys) {
    if (is_scalar($keys)) {
      $proc = drupal_strtolower(trim($keys));
      if (is_numeric($proc)) {
        return ltrim($proc, '-0');
      }
      elseif (drupal_strlen($proc) < $this->options['min_chars']) {
        $this->ignored[$keys] = 1;
        return NULL;
      }
      $words = preg_split('/[^\p{L}\p{N}]+/u', $proc, -1, PREG_SPLIT_NO_EMPTY);
      if (count($words) > 1) {
        $proc = $this->splitKeys($words);
        $proc['#conjunction'] = 'AND';
      }
      return $proc;
    }
    foreach ($keys as $i => $key) {
      if (element_child($i)) {
        //@todo is this really the best place to look for an or?
        if (drupal_strtolower($keys[$i]) == 'or') {
          $keys['#conjunction'] = 'OR';
        }
        $keys[$i] = $this->splitKeys($key);
      }
    }
    return array_filter($keys);
  }

  /**
   * Helper method for eliminating duplicates from the search keys.
   */
  protected function eliminateDuplicates($keys, &$words = array()) {
    foreach ($keys as $i => $word) {
      if (!element_child($i)) {
        continue;
      }
      if (is_scalar($word)) {
        if (isset($words[$word])) {
          unset($keys[$i]);
        }
        else {
          $words[$word] = TRUE;
        }
      }
      else {
        $keys[$i] = $this->eliminateDuplicates($word, $words);
      }
    }
    return $keys;
  }

}
