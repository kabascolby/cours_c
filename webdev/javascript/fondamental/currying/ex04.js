/* we can move nest inside curry, thus reducing the number of 
arguments passed to nest by reading fn and args from the closure. */

function curry(fn){
	const args = [];

	if(fn.length === 0){
		return fn;
	}

	function nest(i){
		return (x) => {
			args.push(x);
			if(i === args.length){
				return fn(...args)
			}
			nest(i + 1);
		};
	};
	return nest(1);
}

/*
Let’s tweak this new curry to be more functional and not rely 
on closure variables. We do this by supplying args and fn.length 
to nest as arguments. Further still, instead of passing the target 
depth (fn.length) for comparison, we can pass the remaining depth of recursion.
*/
// console.log('args = ' + [...args]);
// console.log('x = ' + x);
// console.log('x2 = ' + x);
// console.log('N - 1 = ', N - 1);

function curry2(fn){
	if(fn.length === 0)
		return fn;
	
	function nest(N, args){
		return (x) => {
			if(N - 1 === 0){
				return fn(...args, x);
			}
			return nest(N - 1,[...args, x]);
		};
	};
	return nest(fn.length, []);
}

let val = curry2((a, b, c, d, e) => {
	return a + b + c + d + e;
});
console.log(val);

console.log(val(8)(2)(7)(4)(5));


