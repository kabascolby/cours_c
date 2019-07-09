'use strict'

//prototypical Inheritance
/* 
function Shape (color) {
    this.color = color;
}

Shape.prototype.duplicate = function() {
    
    console.log('Duplicate');
}

function Circle(radius, color){
    Shape.call(this, color); //Super Constructor
    this.radius = radius;
}

Circle.prototype = Object.create(Shape.prototype);
// As a best practice whenerver we reset a prototype of an Object
// We should reset it's constructor to that object
//if we want to implement this behavior
// new Circle.prototype.constructor() is same as new Circle()
Circle.prototype.constructor = Circle;

Circle.prototype.draw = function() {
    console.log('Draw');
}

let c = new Circle(6, 'purple')
 */

 //let refactor our code by creating and Intermediate function inheritance to avoid duplicate code
 // each time when we want to create another object ex: square

function Shape (color) {
    this.color = color;
}

Shape.prototype.duplicate = function() {
    console.log('Duplicate');
}

//intermediate function inheritance
function extend(Child, Parent){
    Child.prototype = Object.create(Parent.prototype);
    Child.prototype.constructor = Child;
}

function Circle(radius, color){
    Shape.call(this, color); //super Constructor
    this.radius = radius;
}
extend(Circle, Shape);

// Method overriding
// it's has to be after the extend function 

Circle.prototype.duplicate = function () { //the child will have the duplicate method as well
    Shape.prototype.duplicate.call(this); // if we want to use the parent method also
    console.log('duplicate circle')
}

Circle.prototype.draw = function() {
    console.log('Draw');
}

let c = new Circle(6, 'purple');