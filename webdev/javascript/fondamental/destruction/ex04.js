// const roomate = {
// 	rm1 : 'Lamine',
// 	rm2 : 'Brendan',
// 	rm3 : 'Pierre',
// 	rm4 : { name: 'Nwang',
// 			age: 26,
// 			sexe: 'M'
// 		},
// 	rm5 : 'Potier'
// }

var roomate = () =>{
	return [
			{ name: 'Nwang',
				age: 26,
				sexe: 'M'
			},
			{
				name: 'Brendan',
				surname: 'Seinsei',
				Alias: 'Dorfnox',
				age: 28,
			}
		]
}

let [Nwang, Brendan] = roomate();
console.log(Nwang)
console.log(Brendan)

const getCar = () => {
	return {
	  brand: 'ferrari',
	  type: 'sportscar',
	  engine: {
		horsepower: 600,
		liters: 4,
		fuel: 'gas'
	  },
	  wheels: 4
	}
  }

let {brand, engine} = getCar();
console.log(brand);
console.log(engine);