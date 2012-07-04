document.addEventListener("deviceready", onDeviceReady, false);
var watchID = null;
var counter = 0;

var map;
var directionsDisplay;
var directionsService = new google.maps.DirectionsService();

var destination = null;
var position = null;
var wayPoints = null;

function onDeviceReady() {
  /*function appReady() {
   console.log("Device ready");

   if (typeof plugins !== "undefined") {
   plugins.localNotification.add({
   date : new Date(),
   message : "Phonegap - Local Notification\r\nSubtitle comes after linebreak",
   ticker : "This is a sample ticker text",
   repeatDaily : false,
   id : 4
   });
   }*/

  var options = {
    enableHighAccuracy : true,
    timeout : 10000
  };
  directionsDisplay = new google.maps.DirectionsRenderer();
  var myOptions = {
    zoom : 15,
    mapTypeId : google.maps.MapTypeId.ROADMAP
  };
  map = new google.maps.Map(document.getElementById("map_canvas"), myOptions);
  directionsDisplay.setMap(map);
  directionsDisplay.setPanel(document.getElementById('directionsList'));

  function onSuccess(pos) {
    position = new google.maps.LatLng(pos.coords.latitude, pos.coords.longitude);
    var marker = new google.maps.Marker({
      position : position,
      map : map
    });
    map.setCenter(position);

    if (destination != null) {
      calcRoute(position, destination);
    }
  }

  function onError(error) {
    alert('code: ' + error.code + '\n' + 'message: ' + error.message + '\n');
  }

  // set up watch position
  watchID = navigator.geolocation.watchPosition(onSuccess, onError, options);

  $('#destinationSubmit').click(function() {
    var destination = document.getElementById('destination').value;
    calcRoute(position, destination);
  });


  $('#remindSubmit').click(remindMe);

  function remindMe() {
    var dateElem = document.getElementById('mydate');
    var timeElem = document.getElementById('mytime');
    var date = dateElem.value;
    var time = timeElem.value;
    var dateSplit = date.split('/');
    var month = parseInt(dateSplit[0], 10) - 1;
    var date = parseInt(dateSplit[1], 10);
    var year = parseInt(dateSplit[2], 10);
    var amOrPm = time.substr(6, time.length);
    var hourMin = time.substr(0, 5).split(':');
    var hour = parseInt(hourMin[0], 10);
    var min = parseInt(hourMin[1], 10);
    if (amOrPm == "PM") {
      hour += 12;
    }
    var destination = document.getElementById('destination').value;
    var dateObject = new Date(year, month, date, hour, min);
    appReady(dateObject);
    var i = false;
    //var xTimer = cordova.require('cordova/plugin/timer');
    //xTimer.add({date : dateObject});
    var intervalID = setInterval(function(){
        console.log("in setInterval");
        /*xTimer.check(function(){
        i = true;
        console.log("success call back");
        },function(){
        console.log("fail call back");
        });
        console.log(i)*/
        console.log(dateObject);
        var d = new Date();
        console.log(d);
        if(dateObject <= d){
          calcRoute(position, destination);
          clearInterval(intervalID);
        }
    }, 1000);
  }

  var i = 5;
  function appReady(myDate) {
    console.log("Device ready");
    console.log(myDate.toString() + "    ||    " + (new Date()).toString());
    
    if ( typeof plugins !== "undefined") {
      plugins.localNotification.add({
        date : myDate,
        message : "Human++ Reminder",
        ticker : "Human++ Reminder",
        repeatDaily : false,
        id : i++
      });
    }
  }

}

function calcRoute(src, des) {
  var request = {
    origin : src,
    destination : des,
    travelMode : google.maps.DirectionsTravelMode.WALKING
  };
  directionsService.route(request, function(res, status) {
    if (status == google.maps.DirectionsStatus.OK) {
      directionsDisplay.setDirections(res);
      wayPoints = res.routes[0].overview_path;
    }
  });
}

var g_bluetoothPlugin = null;

window.addEventListener('load', function() {
  document.addEventListener('deviceready', function() {
  g_bluetoothPlugin = cordova.require('cordova/plugin/bluetooth');
    setInterval(function() {
      if (!wayPoints)
        return;
        var x = wayPoints[0].lat() - position.lat();
      var y = wayPoints[0].lng() - position.lng();
      g_bluetoothPlugin.writefloat(function() {
        console.log('Done writing.');
      }, function(){}, x , y);
    }, 10000);
  }, false);
}, false);

function smifconnect() {
  g_bluetoothPlugin.smifconnect(function() {
    console.log('Connected to Smif');
  }, function(error) {
    alert('Error: ' + error);
  }, $('#bt-devices-select').val(), $('#bt-device-uuids').val());
}

function readRfcomm() {
  //g_bluetoothPlugin.read(bp_readSuccess, bp_readError, g_socketid);
}

function writeRfcomm() {
  g_bluetoothPlugin.write(function() {
    console.log('Done writing.');
  }, bp_readError, "hello");
}

function bp_readError(error) {
  alert('Error: ' + error);
}

function bp_readSuccess(p_data) {
  $('#bt-data-dump').html(p_data);
}
