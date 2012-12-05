#!/usr/bin/perl -w
use strict;

use Cwd;
my $cwd = getcwd;

#-- 
my $emscripten 	= '/home/caiiiycuk/em-sandbox/emscripten';
my $build	 = "$cwd/build";
my $source	 = "$cwd/play-dune/C";
my $makefile = "$build/objs/release/Makefile";
#--
sub execute($);
#--

execute <<"EOC";
rm -rfv $build
cp -rv $source $build
EOC

chdir $build;

execute <<"EOC";
$emscripten/emconfigure $build/configure --without-asound
perl -i -pe "s|dsp_sdl|dsp_none|g;" $makefile
perl -i -pe "s|^LIBS.*|LIBS           =|;" $makefile
perl -i -pe "s|-I/usr/include/SDL|-I$emscripten/system/include/SDL|;" $makefile
VERBOSE=1 $emscripten/emmake make
EOC

# perl -i -pe "s|timer.c||;" $makefile
# perl -i -pe "s|timer.o||;" $makefile

# perl -i -pe "s|opendune|opendune.html|g;" $makefile
# cd build/objs/release/
# --preload-file /home/caiiiycuk/play-dune/data
# EMCC_DEBUG=1 /home/caiiiycuk/em-sandbox/emscripten/emcc  async.o animation.o audio/driver.o audio/dsp_none.o audio/midi_none.o audio/mt32mpu.o audio/sound.o codec/format40.o codec/format80.o config.o crashlog/crashlog.o crashlog/crashlog_none.o explosion.o file.o gfx.o gui/editbox.o gui/font.o gui/gui.o gui/mentat.o gui/security.o gui/viewport.o gui/widget.o gui/widget_click.o gui/widget_draw.o house.o ini.o input/input.o input/mouse.o load.o map.o object.o opendune.o os/error.o pool/house.o pool/structure.o pool/team.o pool/unit.o save.o saveload/house.o saveload/info.o saveload/object.o saveload/saveload.o saveload/scenario.o saveload/scriptengine.o saveload/structure.o saveload/team.o saveload/unit.o scenario.o script/general.o script/script.o script/structure.o script/team.o script/unit.o sprites.o string.o structure.o table/actioninfo.o table/animation.o table/explosion.o table/fileinfo.o table/houseanimation.o table/houseinfo.o table/landscapeinfo.o table/movementtype.o table/selectiontype.o table/sound.o table/structureinfo.o table/teamaction.o table/tilediff.o table/unitinfo.o table/widget.o table/widgetinfo.o table/windowdesc.o team.o tile.o tools.o unit.o video/video_sdl.o wsa.o timer.o -s SAFE_HEAP=1 -s UNALIGNED_MEMORY=1 --pre-js /home/caiiiycuk/play-dune/js/pre.js --preload-file /home/caiiiycuk/play-dune/data -o opendune.html

# LAST:
# perl -w play-dune/support/make.pl
# EMCC_DEBUG=1 /home/caiiiycuk/em-sandbox/emscripten/emcc  async.o animation.o audio/driver.o audio/dsp_none.o audio/midi_none.o audio/mt32mpu.o audio/sound.o codec/format40.o codec/format80.o config.o crashlog/crashlog.o crashlog/crashlog_none.o explosion.o file.o gfx.o gui/editbox.o gui/font.o gui/gui.o gui/mentat.o gui/security.o gui/viewport.o gui/widget.o gui/widget_click.o gui/widget_draw.o house.o ini.o input/input.o input/mouse.o load.o map.o object.o opendune.o os/error.o pool/house.o pool/structure.o pool/team.o pool/unit.o save.o saveload/house.o saveload/info.o saveload/object.o saveload/saveload.o saveload/scenario.o saveload/scriptengine.o saveload/structure.o saveload/team.o saveload/unit.o scenario.o script/general.o script/script.o script/structure.o script/team.o script/unit.o sprites.o string.o structure.o table/actioninfo.o table/animation.o table/explosion.o table/fileinfo.o table/houseanimation.o table/houseinfo.o table/landscapeinfo.o table/movementtype.o table/selectiontype.o table/sound.o table/structureinfo.o table/teamaction.o table/tilediff.o table/unitinfo.o table/widget.o table/widgetinfo.o table/windowdesc.o team.o tile.o tools.o unit.o video/video_sdl.o wsa.o timer.o -O2 --closure 1 -s UNALIGNED_MEMORY=1 --pre-js /home/caiiiycuk/play-dune/play-dune/support/js/pre.js --preload-file /home/caiiiycuk/play-dune/data -o opendune.js

chdir $cwd;

print "Well done\n";

#--
sub execute($) {
	my @lines = split "\n", shift;
	system $_ while $_ = shift @lines;
}