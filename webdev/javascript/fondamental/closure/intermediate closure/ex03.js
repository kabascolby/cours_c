http://javascriptissexy.com/understand-javascript-closures-with-ease/

function displayName(first){
	let x = "My full Name is ";
	return function famillyName(last){
		return x + first + " " + last;
	}
	
}

let name = displayName('Lamine');
console.log(name('kaba'));
console.log(displayName('Mohamed Lamine')('Kaba'));

function userId(){
	var id = 100;
	return {
		getID : () => {
			return id
		},
		setID : (newId) => {
			id = newId
		}
	};
};

let newId = userId();
console.log(newId.getID());
newId.setID(103);
console.log(newId.getID());

function changeID(list){
	let array = list.slice(0);
	let id = 100;
	for(i = 0; i < list.length; i++){
		array[i].id = function() {
			return id + i;
		}
	};
	return array;
};

let myArray = [{Name: 'Lamine', id : 0}, {Name: 'Fanta', id : 0}, {Name: 'Moussa', id : 0}];
let mylist = changeID(myArray);
mylist.forEach(element => {
	console.log('old list', element.id());
});

// To fix this side effect (bug) in closures, 
// you can use an Immediately Invoked Function Expression (IIFE), such as the following:
function fixChangeID(list){
	let i;
	let array = list.slice(0);
	let id = 100;
	for(i = 0; i < list.length; i++){
		array[i].id = function() {
			return id + i;
		}();
	};
	return array;
};
let mylist2 = fixChangeID(myArray);
mylist2.forEach(element => {
	console.log('new list', element.id);
});