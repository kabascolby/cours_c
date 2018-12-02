// http://javascriptissexy.com/understand-javascript-callback-functions-and-use-them/
var clientData = {
	id : 'lkaba',
	fullname: 'Notset',
	setuserName: function setName(first, last){
		this.fullname = `${first} ${last}`;
		// console.log(this.fullname);
	}
};

function getUserInput(first, last, callback){
	if(typeof first === 'string' && typeof last === 'string' && typeof callback === 'function'){
		callback(first, last);
	}
};

// Problem When Using Methods With The this Object as Callbacks

getUserInput('lamine', "kaba", clientData.setuserName);
console.log(clientData);

/* 
Use the Call or Apply Function To Preserve this
We can fix the preceding problem by using the Call or 
Apply function (we will discuss these in a full blog post later). 
For now, know that every function in JavaScript has two methods: Call and Apply.
And these methods are used to set the this object inside the 
function and to pass arguments to the functions.

Call: takes the value to be used as the this object inside the function as the first parameter,
and the remaining arguments to be passed to the function are passed individually
(separated by commas of course).” 
The Apply ”: function’s first parameter is also
the value to be used as the this object inside the function, while the last parameter
is an array of values (or the arguments object) to pass to the function.
*/

function fixUserInput(first, last, callback, thisObject){
	callback.apply(thisObject, [first, last]);
	//same as (thisObjetc, arguments); argument is the array of arguments
}

fixUserInput('Lamine', 'Kaba', clientData.setuserName, clientData);
console.log('\n',clientData);

//same as above by using bind
clientData.setuserName.bind(clientData)('Mohamed', 'keita');
console.log('\n',clientData);