<?php

$pagename = 'Viewer';

$dataFile = '../data.txt';
$rendererExecutable = '../renderer/renderer';
$imageFile = './bitmapImage.bmp';

require('./models/serialize.php');

// Check for incoming data from the form
if(!isset($_POST) || (sizeof($_POST) == 0)) {
    die('No form submitted.<br> <a href="?app">Back to Modell</a>');
}

// Remove previous files
if(file_exists($dataFile)) { unlink($dataFile); }
if(file_exists($imageFile)) { unlink($imageFile); }

// Seralize data & prepare input file
$data = serializeForm($_POST);
file_put_contents($dataFile, $data);

// Execute the renderer
$output = exec($rendererExecutable);

// Dump errors (or temp dump output, treatment after)
if(!file_exists($imageFile)) { $error = 'It seems that there is no rendered image, the renderer may have failed.'; }
if(isset($output) && $output != '') { $error = 'Error code: ' . $output; }

require('./views/view.php');