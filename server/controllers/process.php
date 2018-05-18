<?php

if(!isset($_POST) || (sizeof($_POST) == 0)) {
    die('No form submitted.<br> <a href="?app">Back to Modell</a>');
}

// Init vars
$serializedData = '';

$semiColumns = [];
$i = 0;

// Look for place to put a semi-column
foreach($_POST as $element => $value) {
    // If value is not a number, then use semi-column (seperate objects)
    $semiColumns[$i] = ((intval($value) == 0) && ($value != 0)) ? true : false;

    $i++;
}

// Get maximum interator & reset iterator
$maxI = $i;
$i = 0;

// Serialize data
foreach($_POST as $element => $value) {
    // Look for the good seperator (semi-column or not)
    if($i < $maxI - 1) {
        $seperator = ($semiColumns[$i+1] == true) ? ';' : ',';
    } else {
        $seperator = '';
    }
    
    // Push data
    $serializedData .= $value . $seperator;

    $i++;
}

var_dump($serializedData);