//--
// Cookie support
//--
Module['UUID'] = getCookie('dune-save-uuid') || makeUUID('dune-save-uuid');

function setCookie(c_name,value,exdays) {
  var exdate=new Date();
  exdate.setDate(exdate.getDate() + exdays);
  var c_value=escape(value) + ((exdays==null) ? "" : "; expires="+exdate.toUTCString());
  document.cookie=c_name + "=" + c_value;
};

function getCookie(c_name) {
  var i,x,y,ARRcookies=document.cookie.split(";");
  for (i=0;i<ARRcookies.length;i++) {
    x=ARRcookies[i].substr(0,ARRcookies[i].indexOf("="));
    y=ARRcookies[i].substr(ARRcookies[i].indexOf("=")+1);
    x=x.replace(/^\s+|\s+$/g,"");
    if (x==c_name) {
      return unescape(y);
    }
  }
};

function makeUUID(uuidName) {
  var S4 = function() {
     return (((1+Math.random())*0x10000)|0).toString(16).substring(1);
  };
  var uuid = (S4()+S4()+S4()+S4()+S4()+S4()+S4()+S4());
  setCookie(uuidName, uuid, 365*20);
  return uuid;
};

//--
//	SAVE/LOAD
//--
Module['preRun'] = function() { 
    SDL.defaults.copyOnLock = false;
    Module["FS_findObject"] = FS.findObject;

    var saveFile = 'http://play-dune.com/save/' + Module['UUID'] + '.dat';
	Module["FS_createPreloadedFile"]('/home/caiiiycuk/play-dune/data', 'game.dat', 
    saveFile, true, true);
}

var _saveOnServer = function() {
  file = "/home/caiiiycuk/play-dune/data/game.dat";
  
  var fs_object = Module["FS_findObject"](file);
  var contents = fs_object.contents;
  var array = new Uint8Array(contents);

  var xhr = new XMLHttpRequest();
  xhr.open("POST", "http://play-dune.com/push.php", true);
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
// Other
//--
function _jlog(num) {
	console.log(num);
}