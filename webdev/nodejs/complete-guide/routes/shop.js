const express = require('express');
const path = require('path');
const adminData = require('./admin');

const routeDir = require('../utils/path');

const router = express.Router();


router.get('/', (req, res, next) => {
    // res.sendFile(path.join(routeDir, 'views', 'shop.html'));
    res.render('shop', { prods: adminData.products, pageTitle: 'Shop' })
});

module.exports = router;