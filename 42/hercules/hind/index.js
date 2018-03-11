require('dotenv').config()
const client = require('./app.request-client')
const express = require('express')
const util = require('util')
const fs = require('fs')
const app = express()

// url-encode into a query string
const authData = {
  grant_type: 'client_credentials',
  client_id: process.env.CLIENT_ID,
  client_secret: process.env.CLIENT_SECRET,
};

let currentToken;
let userNames;

app.get('/', (req, res) => res.send('Hello World!'))
app.listen(3000, () => console.log('App listening on port 3000!'))

app.get('/user/:user/locations', function (req, res) {
  const user = req.params.user;

  if (!currentToken) {
    client.post('https://api.intra.42.fr/oauth/token'
    , authData
    , function (data) {
      currentToken = JSON.parse(data);
      retrieveLocations(user, currentToken, res);
    }
    , function (err, data) {
      res.send('#ERROR ' + err);
    });
  } else {
    retrieveLocations(user, currentToken, res);
  }

});

app.get('/users', function (req, res) {
  fs.readFile("./names.txt", "utf8", function (error, data) {
    if (error) {
      res.send(`#ERROR: ${error}`)
    } else if (data) {
      const names = data.trim().split("\r\n");
      let html = '<h3 style=" color: #515198; font-family: verdana; font-size: 150%; margin-left: 25px;">List Users</h3><ul>';
      for (let i = 0; i < names.length; i++) {
        const n = names[i];
        html += `<div style="height: 50px; text-align: center;line-height: 45px; display: table;"><li style="list-style:none;"><a href="/user/${n}/locations">${n}<img src=https://cdn.intra.42.fr/users/small_${n}.jpg style="width:54px;height:42px;border:0;float:left;margin-right: 10px;"></a></li></div>`
      }
      html += '</ul>';
      res.send(html)
    } else {
      res.send('No user names available.')
    }
  });
});

function retrieveLocations(user, token, res) {
  getLocations(user, token, function (data, err) {
    if (err) {
      console.error(err);
      res.send('ERROR ' + err);
    } else {
      if (!util.isArray(data) || data.length === 0) {
        res.send(`User '${user}' does not exist!`);
        return;
      }

      const loc = data[0];

      if (loc.end_at === null) {
        res.send(`User '${user}' is available right now at site ${loc.host}`)
      } else {
        res.send(`User '${user}' is not available right now!`)
      }
    }
  });
}

function getLocations(user, token, callback) {
  client.get(`https://api.intra.42.fr/v2/users/${user}/locations`
    , null
    , function (data) {
      callback(JSON.parse(data));
    }
    , function (err, data) {
      callback(data, err);
    }
    , {
      'Authorization': 'Bearer ' + token.access_token,
      'Content-Type': 'application/x-www-form-urlencoded'
    });
}

function readUserData(user, res) {
  if (!currentToken) {
    client.post('https://api.intra.42.fr/oauth/token'
    , authData
    , function (data) {
      currentToken = JSON.parse(data);
      retrieveLocations(user, currentToken, res);
    }
    , function (err, data) {
      res.send('#ERROR ' + err);
    });
  } else {
    retrieveLocations(user, currentToken, res);
  }
}

