use FindBin;

my $src = $FindBin::Bin;
my $dst = $FindBin::Bin . "/compiled";

print `rm -rfv $dst`;
print `mkdir $dst`;
print `mkdir $dst/js`;
print `mkdir $dst/atreides`;
print `mkdir $dst/ordos`;
print `mkdir $dst/harkonnen`;

print `mkdir $dst/atreides/js`;
print `mkdir $dst/ordos/js`;
print `mkdir $dst/harkonnen/js`;

print `cp -rv $src/img $dst/img`;
print `cp -rv $src/css $dst/css`;
print `cp -rv $src/music $dst/music`;

#print `haml $src/haml/index.haml $dst/index.html`;
print `haml $src/haml/game.haml $dst/atreides/index.html`;
print `haml $src/haml/game.haml $dst/ordos/index.html`;
print `haml $src/haml/game.haml $dst/harkonnen/index.html`;

print `cp $src/js/atreides.js $dst/atreides/js/house.js`;
print `cp $src/js/ordos.js $dst/ordos/js/house.js`;
print `cp $src/js/harkonnen.js $dst/harkonnen/js/house.js`;

print `cp $src/js/opendune.data $dst/atreides/opendune.data`;
print `cp $src/js/opendune.data $dst/ordos/opendune.data`;
print `cp $src/js/opendune.data $dst/harkonnen/opendune.data`;

print `cp $src/js/opendune.js $dst/js/opendune.js`;

print `cp -rv $src/php/* $dst`;