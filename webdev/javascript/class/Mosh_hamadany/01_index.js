/* const circle = {
    radius : 1,
    location: {
        x : 1,
        y : 1,
    },
    draw: function(){
        console.log('draw');
    }
}; */

// factory function

function createCircle(radius){
    return {
        radius, // if the key and the value are the same we can remove the duplication ex: radius : radius => radius,
        draw: function() {
            console.log('draw');
        }
    };
};

const circle = createCircle(1);

circle.draw();
console.log(circle.radius);

// constructor function

function CreateCircle2(radius){
    this.radius = radius;
    this.draw = function() {
        console.log('draw');
    }
};

const circle2 = new CreateCircle2(1);
circle2.draw();