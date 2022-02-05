<?php

$base_url = 'http://localhost/WTL/lab5';

// database credentials

$db_credentials = [
    'host' => 'localhost',
    'user' => 'root',
    'password' => '',
    'name' => 'wtl5'
];

function debug($e){
    print_r('<pre>');
    print_r($e);
}