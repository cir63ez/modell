<?php

function loadAdditionalCss() {
    global $additional_css;

    if(isset($additional_css)) {
        foreach($additional_css as $css_file) {
            echo '<link rel="stylesheet" href="' . $css_file . '">';
        }
    }
}

function loadAdditionalJs() {
    global $additional_js;
    
    if(isset($additional_js)) {
        foreach($additional_js as $js_file) {
            echo '<script src="' . $js_file . '"></script>\n';
        }
    }
}