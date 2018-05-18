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

function addCardAjax(url, container, dropdown, type, id, slideTime) {
    $.ajax({
        'url': url
    }).done(function(data) {
        if (data == "NULL") {
            console.log("Error while loading: ", url);
        } else {
            var iterator = 0;
            var card = $(data);

            container.append(card);
            dropdown.append('<a class="dropdown-item" href="#' + id + '">' + type + ' #' + id + '</a>');
            card.hide().slideDown(200);

            var timer = setInterval(function() {
                if (iterator == slideTime) { clearInterval(timer); }
                card[0].scrollIntoView();
                iterator++;
            }, 1);

            card.find('[data-remove]').click(function() {
                var id = $(this).attr('data-remove');

                removeCard(id);
            });
        }
    })
}

function addObjectCard(objectType, id) {
    objectType = objectType.charAt(0).toUpperCase() + objectType.slice(1);
    var url = "./?card=object" + objectType + "&id=" + id;

    addCardAjax(url, $('fieldset#objects'), objectsDropdown, objectType, id, 200);
}

function addLightCard() {
    var id = "light-" + lightId;
    var url = './?card=lightSource&id=' + id;
    addCardAjax(url, $('fieldset#lights'), lightsDropdown, 'Light', id, 200);

    lightId++;
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