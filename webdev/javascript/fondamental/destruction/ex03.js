const roomate = {
	rm1 : 'Lamine',
	rm2 : 'Brendan',
	rm3 : 'Pierre',
	rm4 : { name: 'Nwang',
			age: 26,
			sexe: 'M'
		},
	rm5 : 'Potier'
}

function printname({rm4, rm4:{age}}){
	console.log(`One of my ningi's name is ${rm4.name} he's ${age} old and I like him.`);
};

printname(roomate);
