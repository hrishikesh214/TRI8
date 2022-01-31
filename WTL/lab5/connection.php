<?php

    require './configs.php';

    $db = new mysqli(
            $db_credentials['host'], 
            $db_credentials['user'], 
            $db_credentials['password'], 
            $db_credentials['name']
        ) 
        or die('Cannot connect to database');
    
