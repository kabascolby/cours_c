var difference = require('lodash/fp/difference')
var intersection = require('lodash/fp/intersection')
var _ = {};

const newDevelopment = [
	{
		name: 'Miss Scarlet',
		present: true,
		rooms: [
			{kitchen: false},
			{ballroom: false},
			{conservatory: true},
			{'dining room': true},
			{'billiard room': false},
			{library: true}
		]
	},
	{
		name: 'Reverend Green',
		present: true,
		rooms: [
			{kitchen: true},
			{ballroom: false},
			{conservatory: false},
			{'dining room': false},
			{'billiard room': true},
			{library: false}
		]
	},
	{
		name: 'Colonel Mustard',
		present: true,
		rooms: [
			{kitchen: false},
			{ballroom: false},
			{conservatory: true},
			{'dining room': false},
			{'billiard room': true},
			{library: false}
		]
	},
	{
		name: 'Professor Plum',
		present: true,
		rooms: [
			{kitchen: true},
			{ballroom: false},
			{conservatory: false},
			{'dining room': true},
			{'billiard room': false},
			{library: false}
		]
	}
];

let reduce = (list, cb, initial) => {
	var i = 0;
	var memo = initial;
	if (memo === undefined) {
		memo = list[i];
		i++;
	}
	if (Array.isArray(list)) {
		for (; i < list.length; i++) {
			memo = cb(list[i], memo, i);
		}
		return memo;
	}
	else {
		for (let k in list) {
			cb(list[k], memo, k);
		}
	}
}

var findEmptyRoom = reduce(newDevelopment, function (item, acc, id){
	for(let k = 0; k < item.rooms.length; k++){
		let v = Object.keys(item.rooms[k])[0];
	  let isTrue = Object.values(item.rooms[k])[0];
	  acc[v] || (acc[v] = []);
	  if(isTrue)
	  acc[v].push(item.name);
	}
	return acc;
	
  }, {});
  console.log(findEmptyRoom); //room list;

  for(let k in findEmptyRoom){
	if(!findEmptyRoom[k].length)
	console.log(`The empty room is: ${k}`); //printing empty room;
};
// console.log(JSON.stringify(newDevelopment, null, '\t'));

_.map = function(list, callback){
    var data = [];
    _.each(list, function (item, i, list){
        data.push(callback(item, i, list));
    });
    return data;
}

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


const notInroom = (list) => {
	const emptyRooms = reduce(list.rooms, (item, value, i) =>{
		// console.log('=>', item)
		if(Object.values(item)[0] === false){
			value.push(Object.keys(item)[0]);
		}
		return value;
	}, []);
	return emptyRooms;
}

var notInrooms = _.map(newDevelopment, notInroom);
console.log('\n\n');
console.log(intersection(...notInrooms)[0]);