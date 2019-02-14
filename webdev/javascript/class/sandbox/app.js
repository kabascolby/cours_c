class Car {
	constructor(doors, engine, color){
		this.doors = doors;
		this.engine = engine;
		this.color = color;
	}

	carStats() {
		return `this car has ${this.doors} doors, a ${this.engine} engine and a beautiful ${this.color} color!`;
	}
	static totalDoors(car1, car2) {
		const doors1 = car1.doors;
		const doors2 = car2.doors;

		return doors1 + doors2;
	}
}

class SUV extends Car{
	constructor(doors, engine, color, brand, carStats){
		super(doors, engine, color, carStats);
		this.brand = brand;
		this.weels = 4;
		this.ac = true;
	}

	myBrand (){
		return `This SUV is a ${this.brand}`;
	}
}

const cx5 = new Car(4, 'v6', 'grey');
console.log(cx5);
const cx6 = new SUV(5, 'v8', 'black', 'tesla');
console.log(cx6);
// console.log(cx5.carStats());
// const civic = new Car(3, 'V4', 'blue');
// console.log(civic);
// console.log(civic.carStats());

// console.log(Car.totalDoors(cx5, civic));
