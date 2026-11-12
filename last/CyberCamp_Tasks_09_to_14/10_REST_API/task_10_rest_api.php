<?php
header("Content-Type: application/json");

$method = $_SERVER['REQUEST_METHOD'];
$headers = function_exists('getallheaders') ? getallheaders() : [];
$raw_data = file_get_contents("php://input");
$data = json_decode($raw_data, true);
$response = [];

switch ($method) {
    case 'GET':
        http_response_code(200);
        $response = ["message" => "GET request received", "headers" => $headers];
        break;
    case 'POST':
        http_response_code(200);
        $response = ["message" => "POST request received", "data" => $data];
        break;
    case 'PUT':
        http_response_code(200);
        $response = ["message" => "PUT request received", "data" => $data];
        break;
    case 'DELETE':
        http_response_code(200);
        $response = ["message" => "DELETE request received"];
        break;
    default:
        http_response_code(405);
        $response = ["error" => "Method not allowed"];
}

if (json_last_error() !== JSON_ERROR_NONE && in_array($method, ['POST', 'PUT'])) {
    http_response_code(400);
    $response = ["error" => "Invalid JSON"];
}

echo json_encode($response, JSON_PRETTY_PRINT);
?>
