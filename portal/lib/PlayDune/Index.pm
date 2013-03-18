package PlayDune::Index;

use Dancer ':syntax';

#Routing

get '/' => sub {
    template 'index';
};

true;