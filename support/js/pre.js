//--
//  DISABLE DEFAULTS
//--
document.body.onselectstart=function() {
  return false
}

document.body.style.MozUserSelect = "none";

if(navigator.userAgent.toLowerCase().indexOf("opera") != -1) {
  document.body.onmousedown = function() {
    return false
  }
}

// --
// -- MIDI --
// --

Module['EM_MIDI_TOGGLE_SOUND'] = function() {
  if (Module['EM_MIDI_MUTED']) {
    Module['EM_MIDI_MUTED'] = false;
    _js_music_play(Module['EM_MIDI_MUTED_AT'] || 0);
  } else {
    Module['EM_MIDI_MUTED'] = true;
    Module['EM_MIDI_MUTED_AT'] = Module['EM_MIDI_CURRENT'];
    _js_driver_music_stop();
  }
};

Module['EM_MIDI_AUDIO'] = new Audio();

Module['EM_MIDI_AUDIO'].addEventListener('ended', function() {
  Module['EM_MIDI_CURRENT'] = 0;
}, false);

Module['EM_MIDI_CURRENT'] = 0;
Module['EM_MIDI_FILES'] = {
  1: '/dune2/music/1.ogg',
  2: '/dune2/music/2.ogg', 
  3: '/dune2/music/3.ogg', 
  4: '/dune2/music/4.ogg', 
  5: '/dune2/music/5.ogg', 
  6: '/dune2/music/6.ogg', 
  7: '/dune2/music/7.ogg', 
  8: '/dune2/music/8.ogg', 
  9: '/dune2/music/9.ogg', 
  10: '/dune2/music/10.ogg', 
  11: '/dune2/music/11.ogg', 
  12: '/dune2/music/12.ogg', 
  13: '/dune2/music/13.ogg', 
  14: '/dune2/music/14.ogg', 
  15: '/dune2/music/15.ogg', 
  16: '/dune2/music/16.ogg', 
  17: '/dune2/music/17.ogg', 
  18: '/dune2/music/18.ogg', 
  19: '/dune2/music/19.ogg', 
  20: '/dune2/music/20.ogg', 
  21: '/dune2/music/21.ogg', 
  22: '/dune2/music/22.ogg', 
  24: '/dune2/music/24.ogg', 
  25: '/dune2/music/25.ogg', 
  26: '/dune2/music/26.ogg', 
  28: '/dune2/music/28.ogg', 
  29: '/dune2/music/29.ogg', 
  30: '/dune2/music/30.ogg', 
  31: '/dune2/music/31.ogg', 
  32: '/dune2/music/32.ogg', 
  33: '/dune2/music/33.ogg', 
  34: '/dune2/music/34.ogg'
};

var _js_music_play = function(index) {
  if (_js_is_muted()) {
    return;
  }

  if (index == Module['EM_MIDI_CURRENT']) {
    return;
  }

  Module['EM_MIDI_CURRENT'] = index;

  if (index == 0) {
    Module['EM_MIDI_AUDIO'].src = Module['EM_MIDI_AUDIO'].src; // rewind
    Module['EM_MIDI_AUDIO'].pause();
    return;
  }

  var url = Module['EM_MIDI_FILES'][index];

  if (url) {
    Module['EM_MIDI_AUDIO'].src = url;
    Module['EM_MIDI_AUDIO'].play();
  }
};

var _js_driver_music_is_playing = function() {
  var isStopped = 
    Module['EM_MIDI_CURRENT'] == 0 ||
    Module['EM_MIDI_AUDIO'].paused ||
    (Module['EM_MIDI_AUDIO'].duration - Module['EM_MIDI_AUDIO'].currentTime) < 10;

  return !isStopped;
}

var _js_driver_music_stop = function() {
  Module['EM_MIDI_CURRENT'] = 0;
  Module['EM_MIDI_AUDIO'].pause();
}

var _js_driver_music_fade_out = function() {
  setTimeout(_js_driver_music_stop, 2000);
}

var _js_is_muted = function() {
  return Module['EM_MIDI_MUTED'];
}

//--
//  STATS
//--

function _pushStats(g_campaignID, houseId, killed, destroyed, harvested, score) {
}