document.body.innerHTML = `<h1 align="center" >I understand Async</h1>
<div  id="weather" style="background-image:url('https://climatekids.nasa.gov/resources/icons/weather-climate.jpg');
width:250px; height:250px; padding:0px 10px;
border-radius: 15px 50px 30px;
background-size: cover;
font-family: 'arial';">
<h2 style="color:#fff;margin:0">Weather</h2>
<hr color=#6579c6>
</div>`;
function get(url) {
	return new Promise(function (resolve, reject) {
		let httpRequest = new XMLHttpRequest();
		httpRequest.open('GET', url);
		httpRequest.onload = function () {
			if (httpRequest.status === 200) {
				resolve(httpRequest.responseText);
			} else {
				reject(Error(httpRequest.status));
			}
		};

		//handling network error
		httpRequest.onerror = function () {
			reject(Error('Network Error'));
		};
		httpRequest.send();
	});
}

function tempToF(kelvin) {
	return ((kelvin - 273.15) * 1.8 + 32);
}

function successHandler(data) {
	const dataObj = JSON.parse(data);
	// console.log(dataObj);
	let element = `
	<h4 style='color:#fff; font-weight:300;font-family: Roboto; margin:8px'>${dataObj.name}:&emsp;${tempToF(dataObj.main.temp).toFixed(2)}&deg;|
	<em style="font-size:0.9em; font-weight: 600; color: #00108e;">${dataObj.weather[0].description}</em></h4>
	`
	return element
}// https://stackoverflow.com/questions/5677799/how-to-append-data-to-div-using-javascript

function failHandler(status) {
	console.log(status);
	let weatherId = document.getElementById("weather");
	weatherId.innerHTML += "<h5>ERROR ON GETTING DATA</h5>";
}

document.addEventListener('DOMContentLoaded', function () {
	const apiKey = '0aa80cd9b32b5a4ea06aa5228f65e230';
	// const url = 'https://api.openweathermap.org/data/2.5/weather?q=fremont&APPID='+ apiKey;
	const locations = [
		'fremont,us',
		'los+angeles,us',
		'san+francisco,us',
		'lone+pine,us',//near to Mount Whitney
		'mariposa,us' //near to Yosemiti Park
	];
	
	const urls = locations.map(location => `https://api.openweathermap.org/data/2.5/weather?q=
	${location}&APPID=${apiKey}`);
	const weatherid = document.getElementById('weather');
	
	// Promise.all([get(urls[0]), get(urls[1]), get(urls[2]), get(urls[3]), get(urls[4])])
	// .then(function (responses) {
	// 	return responses.map(response => successHandler(response));
	// })
	// .then(function(literals){
	// 	literals.forEach(element => weatherid.insertAdjacentHTML('beforeend', element))
	// })
	// .catch(function (status) {
	// 	failHandler(status);
	// })
	// .finally(function () {
		// });
		
		(async function() {
			try {
				let responses = [];
				responses.push(await get(urls[0]));
				responses.push(await get(urls[1]));
				responses.push(await get(urls[2]));
				responses.push(await get(urls[3]));
				responses.push(await get(urls[4]));
			let literals = responses.map(function(response) {
				return successHandler(response);
			});
			document.getElementById('weather').insertAdjacentHTML('beforeend', literals.join(''));
		}
		catch(status) {
			failHandler(status);
		}
		finally {
			weatherid.insertAdjacentHTML('afterend', `<p align="left"><em>@lamine kaba</em></p>`)
		}
	})();
});