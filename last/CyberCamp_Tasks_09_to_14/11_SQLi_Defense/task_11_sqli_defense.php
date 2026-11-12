<?php
header("Content-Type: application/json");

try {
    $pdo = new PDO("sqlite::memory:");
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $pdo->exec("CREATE TABLE users (id INTEGER PRIMARY KEY, username TEXT, password TEXT)");
    $pdo->exec("INSERT INTO users (username, password) VALUES ('alice', 'test123'), ('bob', 'pass456')");

    $username = $_GET['username'] ?? '';
    $unsafe_sql = "SELECT username FROM users WHERE username = '$username'";
    $unsafe_results = $pdo->query($unsafe_sql)->fetchAll(PDO::FETCH_COLUMN);

    $stmt = $pdo->prepare("SELECT username FROM users WHERE username = :username");
    $stmt->execute(['username' => $username]);
    $safe_results = $stmt->fetchAll(PDO::FETCH_COLUMN);

    echo json_encode([
        "input" => $username,
        "unsafe_results" => $unsafe_results,
        "safe_results" => $safe_results
    ], JSON_PRETTY_PRINT);
} catch (Throwable $e) {
    http_response_code(500);
    echo json_encode(["error" => "Request could not be processed"], JSON_PRETTY_PRINT);
}
?>
