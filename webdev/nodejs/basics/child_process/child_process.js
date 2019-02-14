var exec = require('child_process').exec;

// exec("open https://www.djoola.com");
exec("ls -lR ..", function (err, stdout) {
	if(err) throw err;

	console.log("listing finish");
	console.log(stdout);
})