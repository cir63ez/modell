<?php

$dataFile = '../data.txt';
$rendererExecutable = '../renderer/raytester';
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

var_dump($data);

// Execute the renderer
$output = exec($rendererExecutable);

// Dump output
var_dump($output);

// Show image
echo '<img src="' . $imageFile . '" alt="">';