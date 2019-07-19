document.body.innerHTML = `<h1 align="center" >I understand Async</h1>
<div  id="weather" style="background-image:url('https://3c1703fe8d.site.internapcdn.net/newman/gfx/news/hires/2018/1-whytheweathe.jpg');
width:250px; height:250px; padding:0px 10px;
border-radius: 15px 50px 30px;
background-size: cover;
font-family: 'arial';">
<h2 style="color:#000000;margin:0">Weather</h2>
<hr color=#6579c6>
</div>`;
function get(url) {
    return new Promise(function(resolve, reject) {
        let httpRequest = new XMLHttpRequest();
        httpRequest.open('GET', url);
        httpRequest.onload = function() {
            if(httpRequest.status === 200){
                resolve(httpRequest.responseText);
            } else {
                reject(Error(httpRequest.status));
            }
        };

        //handling network error
        httpRequest.onerror = function() {
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
    console.log(dataObj);
    const div = document.getElementById('weather');
    div.insertAdjacentHTML('beforeend', `
    <h5 margin="0">${dataObj.name}:  ${tempToF(dataObj.main.temp).toFixed(2)}&deg;<em>${dataObj.weather[0].description}</em></h5>
    `);
    // https://stackoverflow.com/questions/5677799/how-to-append-data-to-div-using-javascript
}

function failHandler(status) {
    console.log(status);
    let weatherId = document.getElementById("weather");
    weatherId.innerHTML += "<h4>ERROR ON GETTING DATA</h4>";
}

document.addEventListener('DOMContentLoaded', function () {
    const apiKey = '0aa80cd9b32b5a4ea06aa5228f65e230';
    // const url = 'https://api.openweathermap.org/data/2.5/weather?q=fremont&APPID='+ apiKey;
    const locations = [
        'fremont,us',
        'los+angeles,us',
        'san+francisco,us',
        'lone+pine,us',             //near to Mount Whitney
        'mariposa,us' //near to Yosemiti Park
    ];

    const urls = locations.map( location =>`https://api.openweathermap.org/data/2.5/weather?q=
    ${location}&APPID=${apiKey}`);

    Promise.all([get(urls[0]), get(urls[1]), get(urls[2]), get(urls[3]), get(urls[4])])
        .then(function(responses) {
            return responses.map(response => successHandler(response));
        })
        // .then(function(literals){
        //     // console.log(literals);
        // })
        .catch(function(status) {
            failHandler(status);
        })
        .finally(function() {
            let weatherid = document.getElementById("weather");
            weatherid.insertAdjacentHTML('afterend', `<p align="left"><em>@lamine kaba</em></p>`)
        });
});