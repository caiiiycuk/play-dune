package PlayDune::OpenDune;

use Dancer ':syntax';

# Routing

get '/index.php' => sub {
  redirect "/", 301;
};

get '/**/opendune.data' => sub {
  redirect "/opendune.data", 301;
};

get '/**/opendune.js' => sub {
  redirect "/opendune.js", 301;
};

get '/opendune.data' => sub {
  send_file(asset('opendune.data'), system_path => 1);
};

get '/opendune.js' => sub {
  send_file(asset('opendune.js'), system_path => 1);
};

# Impl

sub asset {
  return config->{'data'} . config->{'folder'} . shift;
}

true;