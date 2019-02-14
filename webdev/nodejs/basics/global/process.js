var question = ['what is your name', 'what is your fav hobby?', 'what is your preferred language?'];

var answers = [];
process.stdout.write("hello");

function ask(i){
	process.stdout.write(`\n\n ${question[i]}`);
	process.stdout.write(' > ');
}
process.stdin.on('data', (data) => {
	answers.push(data.toString().trim())
	if(answers.length < question.length){
		ask(answers.length);
	}else{
		process.exit();
	}
})
ask(0);

process.on('exit', () =>{
	process.stdout.write(`\n\n`);
	process.stdout.write(`Go ${answers[1]} ${answers[0]} you can finish writing ${answers[2]} later\n\n`);
})
