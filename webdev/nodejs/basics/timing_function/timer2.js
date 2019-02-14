#!/usr/bin/env node

var waitTime = 10000;
var waitInterval = 500;
var currentTime = 0;
var percentWaited = 0;

console.log('wait for time');

function writeWaitingPercent(p){
	process.stdout.clearLine();
	process.stdout.cursorTo(0);
	process.stdout.write(`waiting... ${p}%`);
}

var interval = setInterval(() => {
	currentTime += waitInterval;
	percentWaited = Math.floor((currentTime/waitTime) * 100);
	writeWaitingPercent(percentWaited);
}, waitInterval);

setTimeout( () =>{
	clearInterval(interval);
	writeWaitingPercent(100);
	console.log('\nDone');
},waitTime);

process.stdout.write('\n');
writeWaitingPercent(percentWaited);