const express = require('express');
const path = require('path');
const adminData = require('./admin');

const routeDir = require('../utils/path');

const router = express.Router();


router.get('/', (req, res, next) => {
    // console.log(adminData.products)
    // res.sendFile(path.join(routeDir, 'views', 'shop.html'));
    res.render('shop', { prods: adminData.products, docTitle: 'Shop' })
});

module.exports = router;