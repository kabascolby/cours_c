class Circle {
    constructor(radius) {
        this.radius = radius;
        this.move = function() { 
            console.log('move');
        }
    }

    draw() {
        console.log('draw');
    }
}

const c = new Circle(1);

// Static instance 

class Circle {
    constructor(radius) {
        this.radius = radius;
    }

    draw() {
        console.log('draw');
    }

    static  parse(obj) {
        let radius = JSON.parse(obj).radius;
        return new Circle(radius);
    }
}


// private properties and methods by using Symbols

const _radius = Symbol();
const _draw = Symbol();

class Circle2 {
    constructor(radius){
        this[_radius] = radius
    }

    [_draw](){
        console.log('draw');
    }
}

let mycircle = new Circle2(1);
//the way to access to symbol property or method value is not easy

let keys = Object.getOwnPropertySymbols(mycircle); //this will return an array of symbols.
console.log(keys);
console.log(mycircle[keys[0]]);

//the second way is to use WeakMaps

const _radius = new WeakMap();
const _move = new WeakMap();

class Circle3 {
    constructor(radius) {
        _radius.set(this, radius);

        _move.set(this, function (){
            console.log('move');
        });
    }

    draw() {
        console.log(_radius.get(this)) //this is the way to access to the WeakMap property
        _move.get(this)(); // here this will return a function and we are executing that function
        console.log('draw');
    }
}

//there is another way to use a variable as a single WeakMap

const privateProps = new WeakMap();

class Circle {
    constructor(radius) {
        privateProps.set(this, {
            radius: radius,
            move: () => {
                console.log('move');
            }
        })
    }
    draw () {
        console.log( privateProps.get(this).radius)
    }
}

//Getter and Setter by using es6 with class;
const _radius = new WeakMap();
const _draw = new WeakMap();

class circle {
    constructor(radius) {
        _radius.set(this, radius);
        _move.set(this, () => {
            console.log('move')
        })
    }
    
    // to access the value of a private property we use the getter get
    // nb: the getter and setter have to be use outside of the constructor
    get radius() {
        return _radius.get(this);
    }
    //to set a new value
    set radius(value) {
        if (value <= 0)
            throw new Error('Invalid radius size');
        _radius.set(this, value);            
    }
}