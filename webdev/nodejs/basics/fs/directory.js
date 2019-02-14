const fs = require('fs');
if(fs.existsSync("lib")){ //it better to use the synchronous part of node js creating the file to avoid error
	console.log("Directory already exist");
}else{
	fs.mkdir("lib", function (err){
		if(err) console.log(err);
		else
			console.log("Directory Created");
	})
}