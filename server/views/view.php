<?php require('./views/head.php'); ?>

<a href="?app" class="btn btn-large btn-primary">Back to Modell</a>

<div class="container text-center">
<?php if(isset($error)): ?>
    Here's an error code: <code><?= $error; ?></code>
<?php else: ?>
    <ul class="nav justify-content-center nav-fill mb-3">
        <li class="nav-item">
            <a href="<?= $imageFile; ?>" class="nav-link" target="_blank">Open image in another tab</a>
        </li>
        <li class="nav-item">
            <a href="<?= $imageFile; ?>" class="nav-link" download>Download image</a>
        </li>
    </ul>

    <img src="<?= $imageFile; ?>" width="100%" alt="Rendered image">
<?php endif; ?>
</div>

<?php require('./views/foot.php'); ?>