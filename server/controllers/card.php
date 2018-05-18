<?php

// Cards list

$cards = [
    'objectEllipsoid' => './views/appCardObjectEllipsoid.php',
    'lightSource' => './views/appCardLightSource.php'
];

// Read card

$card = filter_input(INPUT_GET, 'card');

// Require file or return error code

if(array_key_exists($card, $cards)) {
    require($cards[$card]);
} else {
    die("NULL");
}