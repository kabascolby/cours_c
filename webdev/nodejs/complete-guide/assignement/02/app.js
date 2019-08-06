const path = require('path');
const express = require('express');
const bodyParser = require('body-parser');

const app = express();

const userRoute = require('./routes/users');
const homeRoute = require('./routes/home');


app.use(bodyParser.urlencoded({extended: true}));
app.use(bodyParser.json())

app.use(express.static(path.join(__dirname, 'public')));
app.use('/', (userRoute));
app.use(homeRoute);

app.listen(6600, (err) => {
	if (err) throw err;
	console.log('server running on http://localhost:'+ 6600);
})