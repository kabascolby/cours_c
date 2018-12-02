const newClue = (Name) => {
	var length = Name.length;
	return (weapon) =>{
		// console.log(Name);
		let val = length + weapon.length;
		return !!(val % 1);
	};
};

const name = newClue('lamine');

console.log(name('candleslistik'));
// console.log(newClue('lamine')('candlestik')); //same as above;