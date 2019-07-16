
function mixin(target, ...sources){ // we use rest argument ...[] es6 to collect all the args and turn them into an array
    return Object.assign(target, ...sources); //we use spread operator '...' to expand
}
const canEat = {
    eat: function (){
        this.hunger--;
        console.log('can eat'); 
    }
}

const canWalk = {
    walk : function () {
        console.log('swim');
    }
}

const canSwin = {
    swin : function () {
        console.log('can Swim');
    }
}

function Person () {

}
mixin(Person.prototype, canEat, canWalk);

const duck = mixin({}, canEat, canWalk, canSwin)