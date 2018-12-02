const countNum = () => {
	var x = 0;
	return {
		count : () => { ++x },
		reset : () => { x = 0 },
	};

}