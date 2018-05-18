/*
TODO: Pop modal "addObject"
TODO: Append on modal apply
TODO: Remove object

TODO: Same as above for light sources
*/

var debug = true;

var objectId = 0;
var lightId = 0;

var objectsDropdown = $('#objectsDropdown');
var lightsDropdown = $('#lightsDropdown');

function popObectModal() {
    var id = "object-" + objectId;
    var modalId = "modal-" + id;

    $.ajax({
        url: "./?modal=object&id=" + modalId
    }).done(function(data) {
        if (data === "NULL") {
            console.log("Error while loading modal");
        } else {
            var modal = $(data);

            $('html').append(modal);
            modal.modal();
            modal.find('[data-apply]').click(function() {
                var objectType = modal.find('select')[0].value;

                modal.modal('hide');

                addObjectCard(objectType, id);

            });

            objectId++;
        }
    });
}

function addObjectCard(objectType, id) {
    objectType = objectType.charAt(0).toUpperCase() + objectType.slice(1);

    $.ajax({
        url: "./?card=object" + objectType + "&id=" + id
    }).done(function(data) {
        if (data === "NULL") {
            console.log("Error while loading card");
        } else {
            var card = $(data);

            $('fieldset#objects').append(card);
            objectsDropdown.append('<a class="dropdown-item" href="#' + id + '">' + objectType + ' #' + id + '</a>');
            card.hide().slideDown(200);

            $('[data-remove]').click(function() {
                var id = $(this).attr('data-remove');

                removeCard(id);
            });
        }
    });
}

function addLightCard() {
    var id = lightId;
    var cardId = "light-" + id;

    $.ajax({
        url: "./?card=lightSource&id=" + cardId
    }).done(function(data) {
        if (data == "NULL") {
            console.log("Error while loading card");
        } else {
            var card = $(data);

            $('fieldset#lights').append(card);
            lightsDropdown.append('<a class="dropdown-item" href="#' + cardId + '">Light #' + cardId + '</a>');
            card.hide().slideDown(200);

            $('[data-remove]').click(function() {
                var id = $(this).attr('data-remove');

                removeCard(id);
            });
        }

        lightId++;
    });
}

function removeCard(id) {
    var e = $('#' + id);

    $('a[href$=' + id + ']').remove();

    e.slideUp(200);
    setTimeout(function() {
        e.remove();
    }, 200);
}

$('[data-open=objectModal]').click(popObectModal);
$('[data-apply=lightCard]').click(addLightCard);