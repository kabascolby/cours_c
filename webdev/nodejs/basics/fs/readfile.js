const fs = require('fs');
const path = require('path');

// var content = fs.readFileSync('../global/process.js', "UTF-8");
fs.readdir('../global', (err, files) => {
	files.forEach(f => {
		let file = path.join('../global', f);
		let stats = fs.statSync(file);
		if(stats.isFile()){
			fs.readFile(file, 'UTF-8', (err, data) => {
				console.log('\n', path.basename(file), '\n');
				console.log(`\n--------------------------------------\n${data}\n-------------------------------\n`);
			});
		}
	})
});