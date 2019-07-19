document.body.innerHTML = `<h1 align="center" >I understand Async</h1>
<div  id="weather" style="background-image:url('https://3c1703fe8d.site.internapcdn.net/newman/gfx/news/hires/2018/1-whytheweathe.jpg');
width:250px; height:250px; padding:0px 10px;
border-radius: 15px 50px 30px;
background-size: cover;
color: #900202;">
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
                reject(Error(httpRequest.status))  ;
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
    <h3>${dataObj.name}:  ${tempToF(dataObj.main.temp).toFixed(2)}</h3>
    `);
    return div;
    // https://stackoverflow.com/questions/5677799/how-to-append-data-to-div-using-javascript
}

function failHandler(status) {
    console.log(status);
    let weatherId = document.getElementById("weather");
    weatherId.innerHTML += "<h4>ERROR ON GETTING DATA</h4>";
}

document.addEventListener('DOMContentLoaded', function () {
    const apiKey = '0aa80cd9b32b5a4ea06aa5228f65e230';
    const url = 'https://api.openweathermap.org/data/2.5/weather?q=fremont&APPID='+ apiKey;
    get(url)
        .then(function(response) {
            successHandler(response);
        })
        .catch(function(status) {
            failHandler(status);
        })
        .finally(function() {
            let weatherid = document.getElementById("weather");
            weatherid.insertAdjacentHTML('afterend', `<p align="right"><em>@lamine kaba</em></p>`)
        });
});