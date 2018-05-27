<?php

// App info

define('APP_NAME', 'Modell');
define('APP_VERSION', '1.0.0-dev');

// Needed helpers

require('./helpers/additionalContent.php');

// Basic routing

// Ajax

if(isset($_GET['modal'])) { die(require('./controllers/modal.php')); }
if(isset($_GET['card'])) { die(require('./controllers/card.php')); }

// App
if(isset($_GET['app'])) { die(require('./controllers/app.php')); }

// App process
if(isset($_GET['process'])) { die(require('./controllers/process.php')); }

// Home
die(require('./controllers/home.php'));