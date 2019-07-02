function Circle(radius){
    this.radius = radius;

    let defaultLocation = { x : 1, y : 2}; //defaultLocation is local variable so not accessible from the outside

    this.draw = function(){
        this.getDefaultLocation = function(){
            return defaultLocation; // this is working because of the the closure of the function getDefaultlocation
        }
        console.log('draw');
    }
}

let circle = new Circle(1);


// this methode is not safe because we can still change the value of default location
circle.draw();
let tab = circle.getDefaultLocation();
tab.x = 8;
console.log(tab);
console.log(circle.getDefaultLocation());

// the real purpose of abstraction is to hide the details. So the user should not be able to access the data that
// we dont want him to change

//example 2

function Circle2(radius){
    this.radius = radius;

    let defaultLocation = { x : 1, y : 2}; //defaultLocation is local variable so not accessible from the outside

    this.draw = function(){
        console.log('draw');
    }

    Object.defineProperty(this, 'defaultLocation', {
        get: function() {
            return defaultLocation;
        },
        set: function(value){
            if(!value.x || !value.y){
                throw new Error('Invalide Location');
            }
        }
    });
};

let circle2 = new Circle2(8);
circle2.defaultLocation = 20;

console.log(circle2.defaultLocation);

