function curry(fn) {
	function nest(N, args) {
		return (...xs) => {
			if (xs.length === 0) {
				throw Error('EMPTY INVOCATION');
			}
			if (N - xs.length <= 0) {
				return fn(...args, ...xs);
			}
			return nest(N - xs.length, [...args, ...xs]);
		};
	};
	return nest(fn.length, []);
}

let val = curry((a, b, c, d, e) => {
	return a + b + c + d + e;
});
console.log(val);

console.log(val(8)(2)(7)(4)(5));

let [a, b, ...c] = [1, 2, 3, 4, 5, 6];
console.log(a, b, c);