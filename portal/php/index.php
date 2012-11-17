<?php
include 'config.php';
include 'helper.php';
?>

<html lang='en' xml:lang='en' xmlns='http://www.w3.org/1999/xhtml'>
  <head>

    <title>Dune 2 Online</title>
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

    <div class="footer right">
      Powered by <a href="http://www.opendune.org/" target="_blank">OpenDune</a>, <a href="https://github.com/kripken/emscripten/" target="_blank">Emscripten</a>
      <br/>
       © Aleksander Guryanov <a href="https://github.com/caiiiycuk/play-dune" target="_blank">Feedback</a>
    </div>

    <div class="footer left">
      
    </div>

  </body>
</html>
