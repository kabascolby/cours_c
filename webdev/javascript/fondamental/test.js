let weapons = ['revolver', 'stick', 'arrow', 'Knife'];
var suspect = ['Miss Scarlet', 'colonel Mustard', 'Mr White', 'Diana Pink'];

function createSuspectObject (name){
    return {
        name: name,
        color: name.split(' ')[1],
        speak(){console.log(`My name is ${this.name}`);}
    };
};
var _ = {};

const famille = [
    {
        name: 'Malick',
        sexe: 'M',
    },
    {
        name: 'Lamine',
        sexe: 'M',
    },
    {
        name: 'fanta',
        sexe: 'F',
    },
    {
        name: 'Tenin',
        sexe: 'F',
    },
    {
        name: 'Mamoudou',
        sexe: 'M',
    },
    {
        name: 'Moussa',
        sexe: 'M',
    },
    {
        name: 'Fanta2',
        sexe: 'F',
    },
    {
        name: 'Sory',
        sexe: 'M',
    },
    {
        name: 'Genab',
        sexe: 'F',
    },
    {
        name: 'Kadiatou',
        sexe: 'F',
    },
]


let data = [];

//each;
_.each = (list, callback) => {
    if(Array.isArray(list) === true){
        for(let k in list)
            callback(list[k], k, list);
    }
    else{
        for(let k in list)
            callback(list[k], k, list);
    }

};

//each example
_.each(suspect, function(name){
    data.push(createSuspectObject(name));
});
console.log(data);

//map
_.map = function(list, callback){
    var data = [];
    _.each(list, function (item, i, list){
        data.push(callback(item, i, list));
    });
    // for(let i in list){
    //     console.log(list[i]);
    //     data.push(callback(list[i], i, list));
    // }
    return data;
}

//map example;
console.log(_.map(weapons, function(items){
    return `broken ${items}`;
}))
console.log(_.map(famille, (x) => x.name))

//filter;

_.filter = function (list, callback){
    var data = [];
    _.each(list, (item, i, list) => {
        if(callback(item, i, list) === true)
            data.push(item);
    });
    // for(let i in list){
    //     if(callback(list[i], i, list) === true)
    //         data.push(list[i]);

    // }
    return data;
}
// Filter example
console.log(_.filter(famille, (x) => x.sexe === 'F'));


createTupple = (a, b, c, d) => {
    console.log(a, b, c, d, );
    return [[a,c], [b, d]];
}
console.log(createTupple('it', 'be', 'could', 'anyone', 'no one'));

const constructArray = function(){
    var array = Array.prototype.slice.call(arguments);
    console.log(array);
    array.push('The billard room?');
    console.log('array2', array);
    return array.join(' ');
}

console.log(constructArray('was', 'it', 'in'));

console.log('array_from:', (function(){
    var array = Array.from(arguments);
    array.push('the billard room?');
    return array.join(' ');
})('was', 'it', 'in'))

console.log('\n\n')
const ifElse = (condition, isTrue, isFalse) => {
    return condition ? isTrue() : isFalse();
}
ifElse(true, () => { console.log(true)}, () => { console.log(false)});
console.log(ifElse);

let reduce = (list, cb, initial) => {
    var i = 0;
    var memo = initial === undefined ? (list[i] && (i = 1)) : initial;
    if(Array.isArray(list)){
            for(; i < list.length; i++){
                memo = cb(list[i], memo, i);
            }
        return memo;
    }
    else{
        for(let k in list){
            cb(list[k], memo, k);
        }
    }
}

console.log('My reduce = ', reduce([1,2,3], (x, v) => x + v, ));
console.log('My reduce = ', reduce([1, 2 ,3, 2, 1, 5 , 4, 4], (x, v, i) =>{
// console.log(v)
    (v[x]  || (v[x] = [])).push(x);
    return v;
} , {}));

const newClue = (name) =>{
    const length = name.length;
    return (weapon) => {
        let clue = length + weapon.length;
        return !!(clue % 1);
  	};
};

let value = newClue('clean');
console.log(value);