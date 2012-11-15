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
      <div class='select_house'>
        Select your House
        <img class='absolute' src='/img/select_your_house.png' />
      </div>
      <div class='houses'>
        <div class='house'>
          <a href='/atreides/'>
            Atreides
            <img class='absolute' src='/img/atreides.png' />
          </a>
        </div>
        <div class='spacing'></div>
        <div class='house'>
          <a href='/ordos/'>
            Ordos
            <img class='absolute' src='/img/ordos.png' />
          </a>
        </div>
        <div class='spacing'></div>
        <div class='house'>
          <a href='/harkonnen/'>
            Harkonnen
            <img class='absolute' src='/img/harkonnen.png' />
          </a>
        </div>
      </div>
      <div class='top'>
        Top Commanders
        <a href='top.php'>...</a>
      </div>
      <div class='scores'>
        <ul>
          <? render_top_3_html(); ?>
        </ul>
      </div>
    </div>
    <audio autoplay='autoplay'>
      <source src='/music/28.ogg' type='audio/ogg'></source>
    </audio>
  </body>
</html>
