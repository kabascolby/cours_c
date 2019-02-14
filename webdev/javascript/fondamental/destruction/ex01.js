// https://hackernoon.com/understanding-the-destructuring-assignment-syntax-in-javascript-c3bf8e1e908a


const roommate = ['Lamine', 'Pierre', 'Potier', 'Brendan', 'Nwang'];

let [name1, name2, name3] = roommate.sort();

console.log(name1, name3);

let [, , , name4] = roommate;
console.log(name4);

{
	const roommate = ['Lamine', 'Pierre', 'Potier', 'Brendan', 'Nwang'];
	let [name1, [name2, name3], ...name4] = roommate;
	console.log(name1,name2, name3, name4);
}

{
	const roommate = ['Lamine', 'Pierre', 'Potier', 'Brendan', 'Nwang'];
	let [name1, ...name2] = roommate;
	console.log(name1, '\n', name2);
}