package PlayDune::Play;

use Dancer ':syntax';

# Routing

get '/atreides' => sub {
  redirect '/atreides/', 301;
};

get '/ordos' => sub {
  redirect '/ordos/', 301;
};

get '/harkonnen' => sub {
  redirect '/harkonnen/', 301;
};

get '/:house/' => sub {
  my $player =  var 'player';
  my $house = param('house');

  if ($player->activated()) {
    my $houseLetter = 'a';

    if ($house eq 'ordos') {
      $houseLetter = 'o';
    }

    if ($house eq 'harkonnen') {
      $houseLetter = 'h';
    }

    template 'play', { arguments => "['-$houseLetter']" };
  } else {
    redirect "/commons/login/?go=/$house/";
  }
};

true;