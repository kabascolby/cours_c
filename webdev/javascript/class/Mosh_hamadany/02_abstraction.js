function Circle(radius){
    this.radius = radius;

    let defaultLocation = { x : 1, y : 2}; //defaultLocation is local variable so not accessible from the outside

    this.draw = function(){
        console.log('draw');
    }
    
    this.getDefaultLocation = function(){
        return defaultLocation; // this is working because of the the closure of the function getDefaultlocation
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
        // writable: false,
        // value: defaultLocation,
        // enumerable: false,
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
circle2.defaultLocation.x = 20;
let keys = Object.keys(circle2);
console.log(keys);

console.log(circle2.defaultLocation);
// https://javascriptplayground.com/es5-getters-setters/
// https://www.hongkiat.com/blog/getters-setters-javascript/
// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object/defineProperty

// to read Later
// https://derickbailey.com/2015/10/12/hide-the-backing-variable-of-object-propertiesattributes-using-es6-symbols/ 

