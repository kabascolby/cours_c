document.body.innerHTML = `<h1 align="center" >I understand Async</h1>`;

let httpRequest = new XMLHttpRequest();

function get(url, success, fail) {
    httpRequest.open('GET', url);
    httpRequest.onload = function() {
        if(httpRequest.status === 200){
            success(httpRequest.responseText);
        }
        else {
            fail(httpRequest.status);
        }
    }
    httpRequest.send();
}

function tempToF(kelvin) {
    return ((kelvin - 273.15) * 1.8 + 32);
}

function successHandler(data) {
    const dataObj = JSON.parse(data);
    console.log(dataObj);
    document.body.innerHTML += `
    <div  style="background-color:#afafaf; width:350px; height:350px;">
        <h2>${dataObj.name.toUpperCase()}</h2>
        <h2>${tempToF(dataObj.main.temp).toFixed(2)}</h2>
    </div>
    `
}

function failHandler(status) {
    console.log(status);
    document.body.innerHTML = "<h1>ERROR ON GETTING DATA</h1>";
}

document.addEventListener('DOMContentLoaded', function () {
    const apiKey = '0aa80cd9b32b5a4ea06aa5228f65e230';
    const url = 'https://api.openweathermap.org/data/2.5/weather?q=fremont&APPID='+ apiKey;
    get(url, successHandler, failHandler);
});

//managing get resul here