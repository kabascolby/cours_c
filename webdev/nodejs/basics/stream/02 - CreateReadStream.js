const http = require('http');
const fs = require('fs');

var server = http.createServer(function (req, res){
  var stream = fs.createReadStream(__dirname + '/data.csv');
  stream.pipe(res);
});

server.listen('8000');
