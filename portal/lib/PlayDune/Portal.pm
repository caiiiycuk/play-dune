package PlayDune::Portal;
use Dancer ':syntax';

our $VERSION = '0.1';

use Play::Commons;
use PlayDune::Index;
use PlayDune::Play;
use PlayDune::OpenDune;

any qr{.*} => sub {
  status 'not_found';
  template '404';
};

true;
