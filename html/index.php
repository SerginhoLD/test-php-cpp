<?php

// Test cpp function
//\SerginhoLD\func();

$image = new \SerginhoLD\OpenCV(__DIR__ . '/php.png');
$thumb = $image->thumbnail(__DIR__ . '/php300.png', 300, 300);

echo sprintf('<pre>%s</pre>', print_r([
    'image' => [
        'path' => $image->getPath(),
        'width' => $image->getWidth(),
        'height' => $image->getHeight(),
    ],
    'thumbnail' => [
        'path' => $thumb->getPath(),
        'width' => $thumb->getWidth(),
        'height' => $thumb->getHeight(),
    ],
], true));
