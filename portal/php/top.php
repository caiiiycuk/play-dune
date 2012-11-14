<?php
include 'config.php';
include 'helper.php';
?>

<html lang='en' xml:lang='en' xmlns='http://www.w3.org/1999/xhtml'>
  <head>
    <title>Dune 2 Online</title>
    <meta content='text/html; charset=utf-8' http-equiv='Content-Type' />
    <link href='/css/style.css' rel='stylesheet' type='text/css' />
  </head>
  <body>
    <img class='dune' src='/img/dune.png' />
    <div class='container'>
      <div class='top full'>
        Top Commanders
      </div>
      <div class='scores full'>
        <ol>
			<li class="head">
				<div class='score_player'><a href="#<?=$player?>">Locate myself</a></div>
				<div class='score'><a href="top.php">Score</a></div>
				<div class='score'><a href="top.php?sort=harvested">Harvested</a></div>
				<div class='score'><a href="top.php?sort=destroyed">Destroyed</a></div>
				<div class='score'><a href="top.php?sort=killed">Killed</a></div>
			</li>

<?php 
$sort 	= get_sort_column($_GET['sort']);
$sql 	= get_sql_top($sort);

$mysqli = new mysqli($db_host, $db_user, $db_password, $db_db);
$result = $mysqli->query($sql);

while ($row = $result->fetch_object()){
	$house = get_house($row->house);
	$name = $row->name;

	if ($row->player == $player)  {
		$name = "(YOU) " . $name;
	}

    echo "
<li>
	<div class='score_player'><a class='no-link $house' id='$row->player'>$name</a></div>
	<div class='score $house'>$row->score</div>
	<div class='score $house'>$row->harvested</div>
	<div class='score $house'>$row->destroyed</div>
	<div class='score $house'>$row->killed</div>
</li>	
";
}

$result->close();

$mysqli->close();

?>
        </ol>
      </div>
    </div>
    <audio autoplay='autoplay loop'>
      <source src='/music/28.ogg' type='audio/ogg'></source>
    </audio>
  </body>
</html>