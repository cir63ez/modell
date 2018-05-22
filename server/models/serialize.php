<?php

function nbLights($serialized) {
    return substr_count($serialized, 'light');
}

function nbObjects($serialized) {
    $nbLights = nbLights($serialized);
    $nbSemiColumns = substr_count($serialized, ';');
    
    return $nbSemiColumns - $nbLights;
}

function generalizeCube($cube) {   
    $object = 'brick,' . $cube[1] . ',' . $cube[2] . ',' . $cube[3] . ',';
    $object .= $cube[4] . ',' . $cube[5] . ',' . $cube[6] . ',';
    $object .= $cube[7] . ',' . $cube[8] . ',' . $cube[9] . ',';

    $object .= (int)$cube[4] + (int)$cube[7] - (int)$cube[1] . ',';
    $object .= (int)$cube[5] + (int)$cube[8] - (int)$cube[2] . ',';
    $object .= (int)$cube[6] + (int)$cube[9] - (int)$cube[3] . ',';
    
    $object .= $cube[10] . ',' . $cube[11] . ',' . $cube[12] . ',';

    $object .= (int)$cube[10] + (int)$cube[4] - (int)$cube[1] . ',';
    $object .= (int)$cube[11] + (int)$cube[5] - (int)$cube[2] . ',';
    $object .= (int)$cube[12] + (int)$cube[6] - (int)$cube[3] . ',';

    $object .= (int)$cube[10] + (int)$cube[7] - (int)$cube[1] . ',';
    $object .= (int)$cube[11] + (int)$cube[8] - (int)$cube[2] . ',';
    $object .= (int)$cube[12] + (int)$cube[9] - (int)$cube[3] . ',';

    $object .= (int)$cube[10] + (int)$cube[7] + (int)$cube[4] - 2*(int)$cube[1] . ',';
    $object .= (int)$cube[11] + (int)$cube[8] + (int)$cube[5] - 2*(int)$cube[2] . ',';
    $object .= (int)$cube[12] + (int)$cube[9] + (int)$cube[6] - 2*(int)$cube[3];

    return $object;
}

function generalizePyramid($pyramid) {
    $object = 'brick,' . $pyramid[1] . ',' . $pyramid[2] . ',' . $pyramid[3] . ',';
    $object .= $pyramid[4] . ',' . $pyramid[5] . ',' . $pyramid[6] . ',';
    $object .= $pyramid[7] . ',' . $pyramid[8] . ',' . $pyramid[9] . ',';
    $object .= $pyramid[10] . ',' . $pyramid[11] . ',' . $pyramid[12] . ',';
    $object .= $pyramid[13] . ',' . $pyramid[14] . ',' . $pyramid[15] . ',';
    $object .= $pyramid[13] . ',' . $pyramid[14] . ',' . $pyramid[15] . ',';
    $object .= $pyramid[13] . ',' . $pyramid[14] . ',' . $pyramid[15] . ',';
    $object .= $pyramid[13] . ',' . $pyramid[14] . ',' . $pyramid[15] . ',';

    return $object;
}

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

        if(!is_numeric($value)) {
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
    
        if($split[0] == 'cube') { $dataArray[$index] = generalizeCube($split); }
        if($split[0] == 'pyramid') { $dataArray[$index] = generalizePyramid($split); }
        if($split[0] == 'sphere') { $dataArray[$index] = generalizeSphere($split); }
    }
    
    return implode(';', $dataArray);
}