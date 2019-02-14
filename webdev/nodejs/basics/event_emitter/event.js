#!/usr/bin/env node
var events = require('events');
var emitter = new events.EventEmitter();
emitter.on('customEvent', function(message, status){
	console.log(message, ':', status);
});

emitter.emit('customEvent', "Hello World", 200);