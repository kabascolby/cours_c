<?php
use \Psr\Http\Message\ServerRequestInterface as Request;
use \Psr\Http\Message\ResponseInterface as Response;

require 'vendor/autoload.php';

$app = new \Slim\App;
$app->get('/', function (Request $request, Response $response, array $args) {
    $response->getBody()->write("<h1>Welcome to my PHP docker Container</h1>");

    return $response;
});
$app->run();