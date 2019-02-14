#!/usr/bin/env node
var http = require('http');
var fs = require('fs');

var server = http.createServer((req, res) => {
	fs.readFile(__dirname + '/data.csv', (err, data) => {
		if (err)
			throw Error('Invalide input file.');
		res.end(data);
	});
});

server.listen('8000');

/*
	this code is less effecient because the the page loading have to wait until all the file have to be loaded.
	In case we have low network or there lot of request the server can overflow
	The user experience is poor too because users will need to wait for the whole file to be buffered into memory.
*/