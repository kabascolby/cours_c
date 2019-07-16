class Car {
	constructor(doors, engine, colors){
		this.doors = doors;
		this.engine = engine;
		this.colors = colors;
	}
	carStats(){
		return `This car has ${this.doors} doors, a ${this.engine} engine\
 and a beautiful ${this.colors} color!`
	}
	
	static totalDoors(c1, c2){
		return c1.doors + c2.doors; 
	}

	static createCar(str){
		let car = JSON.parse(str);
		try {
			if(!["doors", "engine", "colors"].every(x => x in car))
				throw new Error('missing property');
			console.log('car created with success');			
		} catch (error) {
			console.log(error.message)
		}
		return new Car(car.doors, car.engine, car.colors);
	}
} 

let brand =  {
	brand,
	model,
	year
}

let carMixin = {
	__proto__ : brand,
}
//extend a class

class SUV extends Car {
	constructor(doors, engine, colors, brand, model, year) {
		super(doors, engine, colors);
		this.brand = brand;
		// Object.assign(this, carMixin);
	}
	carStats(){ //here we redefining a carStats method and assign to the SUV constructor
		// console.log(super.carStats()); here we are Calling the first carStats methods from the Car constructor
		return `This ${this.brand} has ${this.doors} doors, a ${this.engine}  and a beautiful ${this.colors} color!`;
	}
}


//Mixin


let cx5 = new Car(4, 'v5', 'grey');

console.log(cx5)

console.log(cx5.carStats());

console.log(Car.totalDoors(new Car(4, 'v5', 'grey'), new Car(2, 'v5', 'white')));

let bmw = Car.createCar('{"engine" : "v4", "doors" : 4 , "colors" : "red"}');
console.log(bmw.carStats());
let c = new SUV(4, "v4", "red", "peogeot"); 
