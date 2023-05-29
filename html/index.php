<?php

// Test cpp function
#\SerginhoLD\func();

$a = new \SerginhoLD\OpenCV(__DIR__ . '/php.png');
var_dump($a->getPath(), $a->getWidth());
