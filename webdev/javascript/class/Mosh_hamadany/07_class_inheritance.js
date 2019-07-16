class Shape {
    constructor(color) {
        this.color = color;
    }

    move() {
        console.log('move');
    }
}

class Circle extends Shape {
    constructor(color, radius) {
        super(color); // in class when a class inheritate to another class 
        this.radius = radius;//we have use the super keyword to reference the parent constructor;
    }

    draw() { 
        console.log('draw');
    }
}

//method overriding

let c = new Circle('red', 1);

class Shape {
    constructor(color) {
        this.color = color;
    }

    move() {
        console.log('move');
    }
}

class Circle extends Shape {
    constructor(color, radius) {
        super(color); // in class when a class inheritate to another class 
        this.radius = radius;//we have use the super keyword to to reference the parent constructor;
    }

    move() {
        super.move();
        console.log('move this circle');
    }

    draw() { 
        console.log('draw');
    }
}
let c = new Circle('red', 1);
