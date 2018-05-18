<?php $id = (isset($_GET['id'])) ? htmlspecialchars(filter_input(INPUT_GET, 'id'), ENT_QUOTES) : uniqid(); ?>

<div class="card my-2" id="<?= $id; ?>">
    <input type="text" name="<?= $id; ?>" value="light" hidden="hidden">
    <div class="card-header bg-warning h2 text-white"><i class="fas fa-lightbulb"></i> Light source</div>
    <div class="card-body">
        <h4>Position</h4>

        <input type="number" class="form-control" name="<?= $id; ?>_posX" placeholder="X" required>
        <input type="number" class="form-control" name="<?= $id; ?>_posY" placeholder="Y" required>
        <input type="number" class="form-control" name="<?= $id; ?>_posZ" placeholder="Z" required>

        <div class="text-right mt-3">
            <a href="#lights" class="btn btn-danger" data-remove="<?= $id; ?>"><i class="fas fa-trash"></i> Remove</a>
        </div>
    </div>
</div>