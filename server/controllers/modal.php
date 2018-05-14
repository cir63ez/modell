<?php

// Modals list

$modals = [
    'object' => './views/appModalObject.php'
];

// Read modal

$modal = filter_input(INPUT_GET, 'modal');

// Require file or return error code

if(array_key_exists($modal, $modals)) {
    require($modals[$modal]);
} else {
    die("NULL");
}