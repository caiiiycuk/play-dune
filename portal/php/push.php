<?php

$file = $_SERVER['HTTP_X_UUID'];

if ($file) {
  file_put_contents('save/'. $file . '.dat' ,file_get_contents("php://input"));
}

?>