const myAlert =  () => {
	var x = "Help! I think I found a clue!";
	var count = 0;
	const alerter = () =>{
		alert(`${x} ${++count}`);
	};
	return alerter;
}

const funcAlert = myAlert();
const funcAlert2 = myAlert();
funcAlert2();