const roomate = {
	rm1 : 'Lamine',
	rm2 : 'Brendan',
	rm3 : 'Pierre',
	rm4 : 'Nwang',
	rm5 : 'Potier'
}

let {rm1 : name1, rm5: name2} = roomate;

console.log(name1, name2);

/* 
	You can even further optimise this by using a shorthand
	syntax if you don’t mind that the variable name and the
	key name are the same. The above can then be written like this:
*/

{
	let {rm5, rm3} = roomate;
	console.log(rm5, rm3); 
}