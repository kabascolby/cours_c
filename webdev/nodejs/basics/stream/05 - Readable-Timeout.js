var readable = require('stream').Readable;

var rs = new readable;
var c = 97 - 1;
rs._read = function () {
	if (c >= 'z'.charCodeAt(0))
		return rs.push(null);
	setTimeout(() => {
		rs.push(String.fromCharCode(++c));
	}, 150);
}
rs.pipe(process.stdout);

process.on('exit', () => {
	console.error('\nrs.read() called ', (c - 97) + ' times');
});

process.stdout.on('error', process.exit);