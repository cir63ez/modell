<?php require('./views/head.php'); ?>

<nav class="navbar navbar-expand-lg navbar-dark bg-dark fixed-top">
    <a href="#" class="navbar-brand">
        <img src="./assets/img/favicon.png" width="32" alt="favicon">
        Modell App
    </a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbar">
        <span class="navbar-toggler-icon"></span>
    </button>

    <div class="collapse navbar-collapse" id="navbar">
        <ul class="navbar-nav mr-auto">
            <li class="nav-item"><a href="#image" class="nav-link"><i class="far fa-image"></i> Image</a></li>
            <li class="nav-item dropdown">
                <a class="nav-link dropdown-toggle" href="#" data-toggle="dropdown">
                    <i class="fas fa-cubes"></i> Objects
                </a>
                <div class="dropdown-menu" id="objectsDropdown"></div>
            </li>
            <li class="nav-item dropdown">
                <a class="nav-link dropdown-toggle" href="#" data-toggle="dropdown">
                <i class="fas fa-lightbulb"></i> Lights
                </a>
                <div class="dropdown-menu" id="lightsDropdown"></div>
            </li>
        </ul>
    </div>
</nav>

<div class="container">
    <form action="./?process" method="post" id="main">
        <fieldset id="image">
            <div class="card">
                <div class="card-header bg-primary h2 text-white"><i class="far fa-image"></i> Image</div>
                <div class="card-body">
                    <div class="row">
                        <div class="col-6">
                            <h4>Top Left Corner</h4>

                            <input type="number" class="form-control" name="topLeftCornerPosX" placeholder="X" required>
                            <input type="number" class="form-control" name="topLeftCornerPosY" placeholder="Y" required>
                            <input type="number" class="form-control" name="topLeftCornerPosZ" placeholder="Z" required>
                        </div>
                        <div class="col-6 mt-3">
                            <h4>Image dimension</h4>

                            <input type="number" class="form-control" name="imageHeight" placeholder="Height" required>
                            <input type="number" class="form-control" name="imageWidth" placeholder="Width" required>
                        </div>
                    </div>

                    <h4>Plane rotation (radians)</h4>

                    <input type="number" class="form-control" name="rotationX" placeholder="Rotation x" required>
                    <input type="number" class="form-control" name="rotationY" placeholder="Rotation y" required>
                    <input type="number" class="form-control" name="rotationZ" placeholder="Rotation z" required>
                </div>
            </div>
        </fieldset>

        <fieldset id="objects">
        </fieldset>
        
        <div class="text-center mt-3" id="addObject">
            <a href="#addObject" class="btn btn-success btn-small-block" data-open="objectModal"><i class="fas fa-plus"></i> Add an object</a>
        </div>

        <fieldset id="lights">
        </fieldset>

        <div class="text-center mt-3" id="addLightSource">
            <a href="#addLightSource" class="btn btn-success btn-small-block" data-apply="lightCard"><i class="fas fa-plus"></i> Add a light source</a>
        </div>

        <div class="text-center my-3"><input class="btn btn-primary btn-small-block" type="submit" value="Render 🚀"></div>
    </form>
</div>

<?php require('./views/foot.php'); ?>