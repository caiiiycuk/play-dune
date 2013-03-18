Module['UUID'] = Engine['player-uuid'];

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

window.addEventListener("keydown", function(event) {
  if(event.preventDefault) {
    event.preventDefault();
  }
});

//--
//	SAVE/LOAD
//--
Module['preRun'] = function() { 
  SDL.defaults.copyOnLock = false;
  
  var saves = Object.keys(Engine['saves']);
  for (var i = 1; i < 10; ++i) {
    var file = '_save00' + i + '.dat';
    var url = '/save/' + Module['UUID'] + '/' + file;

    Module["FS_createPreloadedFile"]
      ('/home/caiiiycuk/play-dune/data', file, url, true, true);
  }
}

var _selectSlot = function(callback) {
  Module['selectSlotDialog'](function(slot) {
    FUNCTION_TABLE[callback](slot);
  });
}

var _saveOnServer = function(ptr) {
  var fileName = Pointer_stringify(ptr);
  var file = "/home/caiiiycuk/play-dune/data/"+fileName;
  var fs_object = FS.findObject(file);
  var contents = fs_object.contents;
  var array = new Uint8Array(contents);
  
  var xhr = new XMLHttpRequest();
  xhr.open("POST", "/save/" + Module['UUID'] + "/" + fileName, true);
  xhr.setRequestHeader('X-UUID', Module['UUID']);
  xhr.onload = function(e) { 
    alert('This game is saved on the server!');
  };
  xhr.send(array.buffer);
};

// --
// -- MIDI --
// --

Module['EM_MIDI_AUDIO'] = new Audio();

Module['EM_MIDI_AUDIO'].addEventListener('ended', function() {
    this.currentTime = 0;
    this.src = this.src; // rewind
    this.play();
}, false);

Module['EM_MIDI_CURRENT'] = 0;
Module['EM_MIDI_FILES'] = {
  1: '/music/1.ogg',
  2: '/music/2.ogg', 
  3: '/music/3.ogg', 
  4: '/music/4.ogg', 
  5: '/music/5.ogg', 
  6: '/music/6.ogg', 
  7: '/music/7.ogg', 
  8: '/music/8.ogg', 
  9: '/music/9.ogg', 
  10: '/music/10.ogg', 
  11: '/music/11.ogg', 
  12: '/music/12.ogg', 
  13: '/music/13.ogg', 
  14: '/music/14.ogg', 
  15: '/music/15.ogg', 
  16: '/music/16.ogg', 
  17: '/music/17.ogg', 
  18: '/music/18.ogg', 
  19: '/music/19.ogg', 
  20: '/music/20.ogg', 
  21: '/music/21.ogg', 
  22: '/music/22.ogg', 
  24: '/music/24.ogg', 
  25: '/music/25.ogg', 
  26: '/music/26.ogg', 
  28: '/music/28.ogg', 
  29: '/music/29.ogg', 
  30: '/music/30.ogg', 
  31: '/music/31.ogg', 
  32: '/music/32.ogg', 
  33: '/music/33.ogg', 
  34: '/music/34.ogg'
};

var _js_music_play = function(index) {
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

//--
//  STATS
//--

function _pushStats(g_campaignID, houseId, killed, destroyed, harvested, score) {
// var scores = {
//   'campaign': g_campaignID,
//   'house': houseId,
//   'killed': killed,
//   'destroyed': destroyed,
//   'harvested': harvested,
//   'score': score,
//   'player': Module['UUID']
// };
// 
// var xhr = new XMLHttpRequest();
// xhr.open("POST", "http://play-dune.com/stats.php", true);
// xhr.send(JSON.stringify(scores));
}