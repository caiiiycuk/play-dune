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

    <div class="footer left">
      Powered by <a href="http://www.opendune.org/" target="_blank">OpenDune</a>, <a href="https://github.com/kripken/emscripten/" target="_blank">Emscripten</a>
      <br/>
       © Aleksander Guryanov <a href="https://github.com/caiiiycuk/play-dune" target="_blank">Feedback</a>
    </div>

    <div class="footer right">
      <form action="https://www.paypal.com/cgi-bin/webscr" method="post">
      <input type="hidden" name="cmd" value="_s-xclick">
      <input type="hidden" name="encrypted" value="-----BEGIN PKCS7-----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-----END PKCS7-----
      ">
      <input type="image" src="https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
      <img alt="" border="0" src="https://www.paypalobjects.com/ru_RU/i/scr/pixel.gif" width="1" height="1">
      </form>

      <iframe allowtransparency="true" src="https://money.yandex.ru/embed/small.xml?uid=41001419739511&amp;button-text=06&amp;button-size=s&amp;button-color=black&amp;targets=dune+2+online+game&amp;default-sum=50" frameborder="0" height="31" scrolling="no" width="150px"></iframe>
    </div>

  </body>
</html>
