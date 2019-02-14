var waitTime = 3000;
var currentTime = 0;
var waitInterval = 500;

console.log('Wait for it');

var interval = setInterval( () => {
	currentTime += waitInterval;
	console.log(`waiting ${currentTime/1000} seconds...`);
}, waitInterval);

setTimeout(() => {
	clearInterval(interval);
	console.log('Done');
}, waitTime);