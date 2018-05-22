<?php

function nbLights($serialized) {
    return substr_count($serialized, 'light');
}

function nbObjects($serialized) {
    $nbLights = nbLights($serialized);
    $nbSemiColumns = substr_count($serialized, ';');
    
    return $nbSemiColumns - $nbLights;
}

function generalizeCube($cube) {}

function generalizePyramid($pyramid) {}

function generalizeSphere($sphere) {
    $object = 'ellipsoid,' . $sphere[1] . ',' . $sphere[2] . ',' . $sphere[3] . ',';
    $object .= $sphere[4] . ',' . $sphere[4] . ',' . $sphere[4] . ',';

    return $object;
}

function serializeForm($formInput) {
    $serializedData = '';
    $nbSemiColumns = 0;
    $semiColumns = [];
    $i = 0;

    foreach($formInput as $element => $value) {
        $semiColumns[$i] = false;
    
    
        if((intval($value) == 0) && ($value !== 0)) {
            $nbSemiColumns++;
            $semiColumns[$i] = true;
        }

        $i++;
    }

    $maxI = $i;
    $i = 0;

    foreach($formInput as $element => $value) {
        if($i < $maxI - 1) {
            $seperator = ($semiColumns[$i+1] == true) ? ';' : ',';
        } else {
            $seperator = '';
        }
        
        $serializedData .= $value . $seperator;
    
        $i++;
    }

    $nbObjects = nbObjects($serializedData);
    $nbLights = nbLights($serializedData);

    $dataArray = explode(';', $serializedData);
    $dataArray[0] .= implode(';', ['', $nbObjects, $nbLights]);

    foreach($dataArray as $index => $element) {
        $split = explode(',', $element);
    
        //if($split[0] == 'cube') {$dataArray[$index] = generalizeCube($element);}        // Cube -> ?
        if($split[0] == 'sphere') {$dataArray[$index] = generalizeSphere($split);}    // Sphere -> Ellipsoid
    }
    
    return implode(';', $dataArray);
}