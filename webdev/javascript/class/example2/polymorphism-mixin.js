
function mixin(target, ...sources){ // we use rest argument ...[] es6 to return the rest
    Object.assign(target, ...sources); //we use spread operator '...' to expand
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
mixin(person, canEat, canWalk);

mixin(new Object(Duck), canEat, canWalk, canSwin)