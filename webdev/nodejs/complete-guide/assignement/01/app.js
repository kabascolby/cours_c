const http = require('http');
const routes = require('./routes')

const server = http.createServer(routes);

server.listen(8080, (err) => {
	if (err) throw err;
	console.log(`server is running on http://localhost:${server.address().port}`);
})