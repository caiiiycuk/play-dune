<?php
include 'config.php';
include 'helper.php';

if ( isset($_POST['name']) ) {
  update_player_name($_POST['name']);
}

?>

<html lang='en' xml:lang='en' xmlns='http://www.w3.org/1999/xhtml'>
  <head>
  
    <title>Dune 2 Online Top</title>
    <meta content='text/html; charset=utf-8' http-equiv='Content-type' />
    <meta name="description" content="play-dune.com is an open source browser game based upon Dune 2." />
    <meta name="keywords" content="play-dune,play dune,dune,dune2,game,browser,online,play" />
    <meta name="author" content="Guryanov Aleksander" />
    <link rel="icon" type="image/ico" href="/favicon.ico" />

    <script type="text/javascript">

      var _gaq = _gaq || [];
      _gaq.push(['_setAccount', 'UA-36400197-1']);
      _gaq.push(['_trackPageview']);

      (function() {
        var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
        ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
        var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
      })();

    </script>

    <link href='/css/style.css' rel='stylesheet' type='text/css' />
  </head>
  <body>
    <img class='dune' src='/img/dune.png' />
    <div class='container'>
      <div class='top full'>
        <div class="back"><a href="/"><<</a></div>
        Top Commanders
      </div>
      <div class='scores full'>
        <ol>
    			<li class="head">
    				<div class='score_player'><a href="#<?=$player?>">Locate myself</a></div>
    				<div class='score score-right'><a href="top.php">Max score</a></div>
    				<div class='score score-right'><a href="top.php?sort=harvested">Harvested</a></div>
    				<div class='score score-right'><a href="top.php?sort=destroyed">Destroyed</a></div>
    				<div class='score score-right'><a href="top.php?sort=killed">Killed</a></div>
    			</li>
          <?  render_top_html( isset($_GET['sort']) ? $_GET['sort'] : '' ); ?>
        </ol>
      </div>
    </div>

    <div class='underline full'>
      <a id="personal" class="no-link">Personal</a>
    </div>

    <div class="default full">
      <form class="form" action="top.php" method="POST">
        Your name:
        <input name="name" type="text" value="<?=$playerName?>"></input>
        <button class="green-button" type="submit">Change</button>
      </form>
    </div>

    <audio autoplay='autoplay loop'>
      <source src='/music/28.ogg' type='audio/ogg'></source>
    </audio>

  </body>
</html>