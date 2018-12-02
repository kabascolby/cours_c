const myAlert = () => {
	const x = "Help! I think i found a clue!";
	const alerter = () =>{
		alert(x);
	};
	setTimeout(alerter, 1000);
	console.log('what happens first? this log or the alert ?');
};
myAlert();