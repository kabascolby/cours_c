var readable = require('stream').Readable;

// var rs = new readable;
// rs.push('Mohamed Lamine Kaba\n');
// rs.push(null);
// rs.pipe(process.stdout);

(function printOnscreen(str){
	let i = -1;
	var rs = readable();
	while(++i < str.length)
		rs.push(str[i]);
	rs.push('\n');
	rs.push(null);
	rs.pipe(process.stdout);
})(process.argv[2]);

c = 97;
var rs2 = new readable;
rs2._read = function(){
	rs2.push(String.fromCharCode(c++));
	if(c > 'z'.charCodeAt(0))
		rs2.push(null);
}
rs2.pipe(process.stdout);