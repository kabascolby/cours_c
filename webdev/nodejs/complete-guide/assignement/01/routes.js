
	var addUser =  (userDb, user) => {
		if (Array.isArray(userDb)) {
			userDb.push(user);
		}
	};
	
	var renderUsers =  (userDb) =>{
		return `
		<html>
			<head>
			<title>Add the user Info </title>
			</head>
			<body>
				<ul>
					${userDb.map(name => `<li>${name}</li>`).join('')}
				</ul>
			</body>
		</html>`
	}


var users = [];
module.exports = (req, res) => {
	var url = req.url;
	if (url === '/') {
		res.setHeader('Content-Type', 'text/html');
		res.write(`
		<html>
		<head>
		<title>Add the user Info </title>
		</head>
		<body>
			<form action="/create-user" method="POST">
				username: <input placeholder="user name" type="text" name="message"> <button type="submit">Send</button></input>
			</form>
		</body>
		</html>
		`);
		return res.end();
	}

	if (url === '/create-user' && req.method === 'POST') {
		var body = '';
		req.on('data', (chunk, err) => {
			if (err) throw err;
			body += chunk.toString();
		});

		return req.on('end', () => {
			let user = body.split('=')[1]
			addUser(users, user);
			res.writeHead(302, {"location" : "/"})
			res.end();
		})
		
	}
	if (url === '/users'){
		res.setHeader('Content-Type', 'text/html');
		res.write(renderUsers(users));
		return res.end();
	}

	res.setHeader('Content-Type', 'text/html');
	res.write(`
		<html>
			<head>
			<title>Add the user Info </title>
			</head>
			<body>
				<h1>Hello display me this beautiful text</h1>
			</body>
		</html>
	`);
	
	res.end();
}