#!/bin/sh
docker build -t lkaba/php:1.0 .;
docker run --rm --name php_server -v /var/www/html/vendor -p 80:80 lkaba/php:1.0