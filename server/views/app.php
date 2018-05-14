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
            <li class="nav-item"><a href="#" class="nav-link"><i class="fas fa-video"></i> Camera</a></li>
            <li class="nav-item dropdown">
                <a class="nav-link dropdown-toggle" href="#" data-toggle="dropdown">
                    <i class="fas fa-cubes"></i> Objects
                </a>
                <div class="dropdown-menu">
                    <!-- Dropdown exemple -->
                    <h6 class="dropdown-header">Dropdown header</h6>
                    <a class="dropdown-item" href="#">Action</a>
                    <a class="dropdown-item" href="#">Another action</a>
                    <div class="dropdown-divider"></div>
                    <a class="dropdown-item" href="#">Something else here</a>
                </div>
            </li>
            <li class="nav-item"><a href="#" class="nav-link"><i class="fas fa-lightbulb"></i> Lights</a></li>
            <li class="nav-item"><a href="#" class="nav-link"><i class="fas fa-star"></i> Animate</a></li>
        </ul>
    </div>
</nav>

<div class="container">
    <form action="./" mehod="post">
        <input type="text" name="process" value="true" hidden="hidden">
        <fieldset id="camera">
            <div class="card">
                <div class="card-header bg-primary h2 text-white"><i class="fas fa-video"></i> Camera</div>
                <div class="card-body">
                    <div class="form-group">
                        <div class="row">
                            <div class="col-6">
                                <h4>Position</h4>
                                <input type="number" class="form-control" name="cameraPositionX" placeholder="X">
                                <input type="number" class="form-control" name="cameraPositionY" placeholder="Y">
                                <input type="number" class="form-control" name="cameraPositionZ" placeholder="Z">
                            </div>
                            <div class="col-6">
                                <h4>Vector</h4>
                                <input type="number" class="form-control" name="cameraVectorX" placeholder="X">
                                <input type="number" class="form-control" name="cameraVectorY" placeholder="Y">
                                <input type="number" class="form-control" name="cameraVectorZ" placeholder="Z">
                            </div>
                        </div>
                    </div>

                    <h4>Field of view</h4>
                    <div class="form-group">
                        <input type="number" class="form-control" name="cameraFieldOfView" placeholder="Field of view">
                    </div>
                </div>
            </div>
        </fieldset>

        <fieldset id="objects">
            <div class="text-center mt-3" id="addCamera">
                <a href="#" class="btn btn-success"><i class="fas fa-plus"></i> Add an object</a>
            </div>
        </fieldset>

        <fieldset id="lights">
            <div class="text-center mt-3" id="addCamera">
                <a href="#" class="btn btn-success"><i class="fas fa-plus"></i> Add a light source</a>
            </div>
        </fieldset>

        <div class="text-center my-3"><input class="btn btn-primary" type="submit" value="Render 🚀"></div>
    </form>
</div>

<?php require('./views/foot.php'); ?>