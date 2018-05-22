<?php

// Cards list

$cards = [
    // Objects
    'objectBrick' => './views/appCardObjectBrick.php',
    'objectCube' => './views/appCardObjectCube.php',
    'objectEllipsoid' => './views/appCardObjectEllipsoid.php',
    'objectPyramid' => './views/appCardObjectPyramid.php',
    'objectSphere' => './views/appCardObjectSphere.php',
    'objectTetrahedron' => './views/appCardObjectTetrahedron.php',
    
    // Lights
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