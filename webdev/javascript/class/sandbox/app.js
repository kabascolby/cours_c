class Car {
	constructor(doors, engine, colors){
		this.doors = doors;
		this.engine = engine;
		this.colors = colors;
	};
	carStats(){
		return `This car has ${this.doors} doors, a ${this.engine} engine\
		and a beautiful ${this.colors} color!`
	}
} 

let cx5 = new Car(4, 'v5', 'grey');
console.log(cx5)

console.log(cx5.carStats());