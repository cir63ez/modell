<!doctype html>
<html lang="en">

<head>
    <title><?= APP_NAME ?><?php if(strlen($pagename) > 0) {echo ' - ';} ?><?= $pagename; ?></title>

    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <link rel="shortcut icon" href="./assets/img/favicon.ico" type="image/x-icon">
    <link rel="icon" href="./assets/img/favicon.png" type="image/png">
    <link rel="stylesheet" href="./assets/css/bootstrap.min.css">
    <!-- <link rel="stylesheet" href="./assets/css/bootstrap.materia.min.css">-->
    <link rel="stylesheet" href="./assets/css/fontawesome.min.css">
    <link rel="stylesheet" href="./assets/css/fa-brands.min.css">
    <link rel="stylesheet" href="./assets/css/fa-regular.min.css">
    <link rel="stylesheet" href="./assets/css/fa-solid.min.css">
    <?php loadAdditionalCss(); ?>
</head>

<body>