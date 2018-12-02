var allUserData = [];
function logStuff(userData){
	if (typeof userData === "string"){
		console.log(userData);
	}
	else if(typeof userData === "object"){
		for(let item in userData){
			console.log(item + 	": " + userData[item].name + ` ${userData[item].age} old`);
		}
	}
}

function getInput(option, callback){
	allUserData.push(option);
	if(typeof callback === "function")
		callback(option);
}

getInput([{name: "lamine", age: 21}, {name : "Pierre", age: 25}], logStuff);