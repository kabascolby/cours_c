// https://hackernoon.com/currying-in-js-d9ddc64f162e
let add = function (a, b){
	console.log(a, b);
	return a + b;
}

let add2 = add.bind(null, 2);
console.log(add2(10));

function curry(fn){
	return (...xs) => {
		if (xs.length === 0){
			throw Error('Empty argument');
		}
		
		if (xs.length === fn.length){
			console.log('xs = ', ...xs);
			return fn(...xs);
		}
		return curry(fn.bind(null, ...xs));
	};
};

let cur = curry((a, b, c, d, e) => console.log (a + b + c + d + e));

cur(1, 2)(3 , 4)(5)