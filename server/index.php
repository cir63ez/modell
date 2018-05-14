<?php

// App info

define('APP_NAME', 'Modell');
define('APP_VERSION', '1.0.0-dev');

// Needed helpers

require('./helpers/additionalContent.php');

// Basic routing
if(isset($_GET['modal'])) {
    require('./controllers/modal.php');
} elseif(isset($_GET['app'])) {
    require('./controllers/app.php');
} else {
    require('./controllers/home.php');
}
