const path = require('path');

const express = require('express');
const bodyParser = require('body-parser');

const PORT = 8000;
const app = express();

// app.set('view engine', 'pug');
app.set('view engine', 'ejs');

app.set('views', 'views/ejs');

const adminData = require('./routes/admin');
const shopRoutes = require('./routes/shop');


app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(express.static(path.join(__dirname, 'public')))

app.use('/admin', adminData.routes);
app.use(shopRoutes);

app.use((req, res, next) => {
    // res.status(404).sendFile(path.join(__dirname, 'views', '404.html'));
    res.status(404).render('404', { pageTitle: 'Page Not Found' });
});


app.listen(PORT, (err) => {
    if (err) throw err;
    console.log('server runnin on http://localhost:' + PORT);
});