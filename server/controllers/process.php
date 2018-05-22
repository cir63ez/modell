<?php

$dataFile = '../data.txt';
$rendererExecutable = '../renderer/raytester';
$imageFile = './bitmapImage.bmp';

require('./models/serialize.php');

// Check for incoming data from the form
if(!isset($_POST) || (sizeof($_POST) == 0)) {
    die('No form submitted.<br> <a href="?app">Back to Modell</a>');
}

if(file_exists($dataFile)) { unlink($dataFile); }
if(file_exists($imageFile)) { unlink($imageFile); }

$data = serializeForm($_POST);
file_put_contents($dataFile, $data);

$output = exec($rendererExecutable);

var_dump($output);

echo '<img src="' . $imageFile . '" alt="">';