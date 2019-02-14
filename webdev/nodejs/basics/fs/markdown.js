#!/usr/bin/env node
var readline = require('readline');
rl = readline.Interface(process.stdin, process.stdout);
const fs = require('fs');
var realPerson = {
	name:'',
	sayings: [],
}

rl.question('What is the name of the real persone? ', function (answer) {
	realPerson.name = answer;

	fs.writeFileSync(realPerson.name + ".md", `${realPerson.name}\n=======================\n\n`);
	rl.setPrompt(`What quote ${realPerson.name}  would say? `); //to set the prompt message;
	rl.prompt(); //to display the prompt message;

	rl.on('line', (saying) => { //here is to listen the from the prompt
		if (saying.toLowerCase().trim() === 'exit') {
			rl.close();
		}
		else {
			realPerson.sayings.push(saying.trim());
			fs.appendFile(realPerson.name + ".md", `* ${saying.trim()} \n`, (err) => {
				if (err) throw err;
			})
			rl.setPrompt(`What else ${realPerson.name} would say? ('exit' to leave) `);
			rl.prompt();
		}
	});
});

rl.on('close', () => {
	console.log("%s is a real person who's favorite quotes are %j", realPerson.name, realPerson.sayings);
	process.exit();
})