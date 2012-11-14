<?php

include 'config.php';

$content = file_get_contents("php://input");

$object = json_decode($content);

if (isset($object->player) && isset($object->campaign) &&
    isset($object->score) && 
    isset($object->killed) && isset($object->destroyed) &&
    isset($object->harvested) &&
    isset($object->house)) {

  $mysqli = new mysqli($db_host, $db_user, $db_password, $db_db);
  $mysqli->query("insert into scores(player, house, campaign, score, killed, destroyed, harvested) values('$object->player', $object->house, $object->campaign, $object->score, $object->killed, $object->destroyed, $object->harvested);");
  $mysqli->close();
} else {
	header('HTTP/1.1 500 Internal Server Error');
	echo('Stats object is broken<br/>');
	var_dump($object);
}

?>