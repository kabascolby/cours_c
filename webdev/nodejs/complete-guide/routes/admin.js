const path = require('path');

const express = require('express');
const routDir = require('../utils/path');

const products = [];

const router = express.Router();

router.get('/add-product', (req, res, next) => {
    // res.sendFile(path.join(routDir, 'views', 'add-product.html'));
    res.render('add-product', { pageTitle: 'Add Product' });
});

router.post('/add-product', (req, res, next) => {
    products.push({ title: req.body.title });
    res.redirect('/');
});

module.exports = {
    routes: router,
    products
};