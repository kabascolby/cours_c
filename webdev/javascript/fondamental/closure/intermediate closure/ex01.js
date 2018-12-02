const setTimer = () => {
	var elapsed = 0;
	let stopwatch = () => elapsed;
	let increase = () => elapsed++;
	setInterval(increase, 1000);
	return stopwatch;
}