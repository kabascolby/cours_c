var waitTime = 10000;
var currentTime = 0;
var waitInterval = 5;
var percentWaited = 0;

console.log('whait for It\n');

function writeWaintingPercent(p){
	process.stdout.clearLine();
	process.stdout.cursorTo(0);
	process.stdout.write(`waiting... ${p}%`);
}

var interval = setInterval(() => {
	currentTime += waitInterval;
	percentWaited = Math.floor((currentTime /waitTime) * 100);
	writeWaintingPercent(percentWaited);
}, waitInterval);

setTimeout( () =>{
	clearInterval(interval)
	writeWaintingPercent(100);
	console.log('\ndone\n');

}, waitTime)

writeWaintingPercent(percentWaited);