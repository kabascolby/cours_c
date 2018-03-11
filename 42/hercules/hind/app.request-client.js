const request = require('request')

function HttpClient() {  
}

HttpClient.prototype.get = function(uri, data, onsuccess, onfail, headers) {
    return this.send(uri, data, 'GET', onsuccess, onfail, headers);
};

HttpClient.prototype.post = function(uri, data, onsuccess, onfail, headers) {
    return this.send(uri, data, 'POST', onsuccess, onfail, headers);
};

HttpClient.prototype.send = function(uri, data, method, onsuccess, onfail, headers) {
    const formData = JSON.stringify(data||{});
    
    const options = {
        headers: headers || { 'Content-Type': 'application/json', 'Content-Length': formData.length },
        uri: uri,
        body: formData,
        method: method || 'GET'
    };

    return request(options, function (err, resp, body) {
        if (err) {
            if (typeof onfail === 'function') {
            onfail(err, body);
            } else {
            console.error('ERROR ' + err);
            }
        } else if (onsuccess) {
            onsuccess(body);
        } else {
            console.log(body);
        }
    });
}

exports.get = HttpClient.prototype.get;
exports.post = HttpClient.prototype.post;
exports.send = HttpClient.prototype.send;
