<?php
// turn on all errors
error_reporting(E_ALL);

dl('pdm.so');

// autoloader
$loader = (new \Pdm\Autoload\Loader)
    ->register()
    ->setPrefixes([
        '\Pdm' => [__DIR__ . '/src'],
    ]);

// default globals
if (is_readable(__DIR__ . '/globals.dist.php')) {
    require __DIR__ . '/globals.dist.php';
}

// override globals
if (is_readable(__DIR__ . '/globals.php')) {
    require __DIR__ . '/globals.php';
}
