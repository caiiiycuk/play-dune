package PlayDune::Play;

use Dancer ':syntax';

my $pageTitle = "Dune II The Building of A Dynasty - ";
my $pageMeta = "Here you can play in Dune II for a house ";

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

    template 'play', { 
      pageTitle => $pageTitle . ucfirst($house),
      pageMeta => $pageMeta . $house,
      arguments => "['-$houseLetter']" 
    };
  } else {
    redirect "/commons/login/?go=/$house/";
  }
};

true;