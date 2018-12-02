function sum(a,b,c){
	return a + b + c;
}
console.log(sum(1,2, 3));

function sum2(a){
	return function(b){
		return function(c){
			return a + b + c;
		};
	};
};
console.log(sum2(1)(2)(3));