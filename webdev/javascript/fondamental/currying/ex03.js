/* function nest(cb){
	return (n) =>{
		return nest(cb);
	}
}

function curry(cb){
	return nest(cb);
} */

function nest(cb, args, i){
	return (x) => {
		console.log('x = ' + x);
		args.push(x);
		if (i === cb.length){
			return cb(...args);
		}
		return nest(cb, args, i + 1);
	};
};

function curry(cb){
	const args = [];
	if(cb.length === 0){
		return cb;
	}
	return nest(cb, args, 1);
};

let val = curry((x) => console.log(x));
val(20);
let val2 = curry((x, y) => console.log(x, y));
val2(20)(40);