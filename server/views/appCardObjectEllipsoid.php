<?php $id = (isset($_GET['id'])) ? htmlspecialchars(filter_input(INPUT_GET, 'id'), ENT_QUOTES) : uniqid(); ?>

<div class="card my-2" id="<?= $id; ?>">
    <input type="text" name="<?= $id; ?>" value="ellipsoid" hidden="hidden">
    <div class="card-header bg-info h2 text-white"><i class="fas fa-cube"></i> Object - Ellipsoid</div>
    <div class="card-body">
        <div class="row">
            <div class="col-6">
                <h4>Center</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_centerX" placeholder="X" required>
                <input type="number" class="form-control" name="<?= $id; ?>_centerY" placeholder="Y"required>
                <input type="number" class="form-control" name="<?= $id; ?>_centerZ" placeholder="Z"required>
            </div>
            <div class="col-6">
                <h4>Semi axis</h4>

                <input type="number" class="form-control" name="<?= $id; ?>_semiAxisA" placeholder="a" required>
                <input type="number" class="form-control" name="<?= $id; ?>_semiAxisB" placeholder="b" required>
                <input type="number" class="form-control" name="<?= $id; ?>_semiAxisC" placeholder="c" required>
            </div>
        </div>

        <h4>Color</h4>

        <input type="number" class="form-control"name="<?= $id; ?>_colorR" placeholder="R" required>
        <input type="number" class="form-control"name="<?= $id; ?>_colorG" placeholder="G" required>
        <input type="number" class="form-control"name="<?= $id; ?>_colorB" placeholder="B" required>

        <div class="text-right mt-3">
            <a href="#objects" class="btn btn-danger" data-remove="<?= $id; ?>"><i class="fas fa-trash"></i> Remove</a>
        </div>
    </div>
</div>