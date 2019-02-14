var Person = require("./bin/person");

var lamine = new Person('Lamine Kaba');

lamine.on('speak', function(said){
	console.log(`${this.name} quote << ${said} >>`);
})

lamine.emit('speak', 'Never give up on your dream');

var hussain = new Person('hussain');

hussain.on('speak', function(language){
	console.log(this.name, '->', language);
});

hussain.emit('speak', 'Javascript is the future');