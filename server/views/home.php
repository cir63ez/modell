<?php require('./views/head.php'); ?>

<div class="jumbotron text-center">
    <h1 class="display-3"><?= APP_NAME ?></h1>
    <div id="wrapper">
        <div id="homeCarousel" class="carousel slide" data-ride="carousel">
            <ol class="carousel-indicators">
                <li data-target="#homeCarousel" data-slide-to="0" class="active"></li>
                <li data-target="#homeCarousel" data-slide-to="1" class="active"></li>
                <li data-target="#homeCarousel" data-slide-to="2" class="active"></li>
            </ol>
            <div class="carousel-inner">
                <div class="carousel-item active">
                    <img src="./assets/img/carousel-1.jpeg" alt="" class="d-block w-100">
                    <div class="carousel-caption d-none d-md-block">
                        <h1 class="text-white">An ambious project !</h1>
                    </div>
                </div>
                <div class="carousel-item">
                    <img src="./assets/img/carousel-2.jpeg" alt="" class="d-block w-100">
                    <div class="carousel-caption d-none d-md-block">
                        <h1 class="text-body">An open-source project !</h1>
                    </div>
                </div>
                <div class="carousel-item">
                    <img src="./assets/img/carousel-3.jpeg" alt="" class="d-block w-100">
                    <div class="carousel-caption d-none d-md-block">
                        <h1 class="text-warning">A project that works !</h1>
                    </div>
                </div>
            </div>
            <a href="#homeCarousel" class="carousel-control-prev" data-slide="prev">
                <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                <span class="sr-only">Previous</span>
            </a>
            <a href="#homeCarousel" class="carousel-control-next" data-slide="next">
                <span class="carousel-control-next-icon" aria-hidden="true"></span>
                <span class="sr-only">Next</span>
            </a>
        </div>
    </div>   
            

    <p class="lead mt-3">
        <a href="./?app" class="btn btn-primary btn-lg" role="button">Use Modell</a>
    </p>
</div>

<?php require('./views/foot.php'); ?>