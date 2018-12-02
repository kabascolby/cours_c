function _sum(x, y, z) {
	return x + y + z;
}

function sum(x) {
	return (y) => {
		return (z) => {
			return _sum(x, y, z);
		}
	}
}

console.log(sum(4)(5)(1));


function curry(cb){
	return (x) => {
		return (y) => {
			return (z) =>{
				return cb(x, y, z);
			}
		}
	}
}

let sum2 = curry((a, b, c) => {
	return a + b + c;
});
console.log(sum2(1)(2)(3));
console.log(curry(_sum)(4)(5)(1))