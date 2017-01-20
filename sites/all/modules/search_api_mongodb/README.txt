MongoDB back end for Search API.

Requirements:
- SearchAPI (http://drupal.org/project/search_api)
- MongoDB (http://www.mongodb.org/)
- MongoDB Module (http://drupal.org/project/mongodb)

MongoDB Configuration
- Optional, if you do not do this, the module will use host = localhost, db = default, collection = default
- Set a variable for your available mongo connections:
  $conf['mongodb_connections'] = array(
    'drupalsearch' => array('host' => 'localhost', 'db' => 'drupalsearch'),
  );

- Set a variable for your mongo collections
  $conf['mongodb_collections'] = array(
    'drupalsearch' => 'logginghost',
  );

Installation:
- Enable SearchAPI and MongoDB
- Create a new search server (admin/config/search/search_api)
  - Select "MongoDB service" as the Service Class.
- Create a new search index (admin/config/search/search_api)
  - Select which entity type this search will provide.
  - Select your new MongoDB service as the "Server".
- After creating your server and index, configure the fields to index.
- Create a search page (admin/config/search/search_api/page)

