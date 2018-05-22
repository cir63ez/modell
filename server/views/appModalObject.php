<?php $id = (isset($_GET['id'])) ? htmlspecialchars(filter_input(INPUT_GET, 'id'), ENT_QUOTES) : uniqid(); ?>

<div class="modal" id="<?= $id; ?>">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h5 class="modal-title">Add an object</h5>
                <button type="button" class="close" data-dismiss="modal">
                    <span>&times;</span>
                </button>
            </div>
            <div class="modal-body">
                <h6>Select the type of the object :</h6>
                <select name="objectType" class="custom-select">
                    <option value="brick">Brick</option>
                    <option value="cube" disabled>Cube</option>
                    <option value="ellipsoid" selected>Ellipsoid</option>
                    <option value="pyramid">Pyramid</option>
                    <option value="sphere">Sphere</option>
                    <option value="tetrahedron">Tetrahedron</option>
                </select>
            </div>
            <div class="modal-footer">
                <button type="button" class="btn btn-primary" data-apply>Add</button>
                <button type="button" class="btn btn-danger" data-dismiss="modal">Cancel</button>
            </div>
        </div>
    </div>
</div>