let person = {name : 'lamine Kaba'};

let objectBase = Object.getPrototypeOf(person); //to get all the properties of an object
let descriptor = Object.getOwnPropertyDescriptor(objectBase, 'toString'); //to display the property descriptor of to String method
console.log('objectBase -------------> ', objectBase);
console.log('\n descriptor -------------> ', descriptor);

// instance Property and method and Implementation

function Circle(radius){
    this.radius = radius;
}

// prototype property and methode  implementation
Circle.prototype.draw = function(){
    console.log('draw');
}
Circle.prototype.toString = function(){
    return 'Circle with radius ' + this.radius;
}

let c1 = new Circle(4);

