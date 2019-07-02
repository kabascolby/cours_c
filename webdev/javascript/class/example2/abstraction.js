function Circle(radius){
    this.radius = radius;
    let defaultLocation = {
        x : 0,
        y : 0,
    }
    this.draw = function(){
        console.log(defaultLocation);
        console.log('draw');
    }
}

let circle = new Circle(10);
circle.draw();

