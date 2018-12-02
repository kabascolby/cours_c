var findSomeone = () => {
	let speak = () => {
		console.log(who);
	}
	let who = 'Lamine is the speaker';
	return speak;
}

let speaker = findSomeone();
speaker();