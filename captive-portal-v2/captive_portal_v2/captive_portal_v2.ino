/*
    ESP32 Captive Portal Example
    Libraries:
        - WiFi.h (ESP32 Arduino Core v2.0.0+)
        - WebServer.h (ESP32 Arduino Core v2.0.0+)
        - DNSServer.h (ESP32 Arduino Core v2.0.0+)
*/

//ESP Async WebServer @ 3.8.0
//AsyncTCP @ 1.1.4

#include <WiFi.h>         // ESP32 WiFi library
#include <WebServer.h>    // ESP32 WebServer library
#include <DNSServer.h>    // ESP32 DNS Server library

// WiFi credentials
const char* ssid = "Free WiFi";
const char* password = "";

// DNS settings
const byte DNS_PORT = 53;
DNSServer dnsServer;

// Web server on port 80
WebServer webServer(80);

// HTML page to display
const char* htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Captive Portal</title>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Welcome to the ESP32 Captive Portal!</h1>
    <p>This is a test page.</p>
</body>
</html>
)rawliteral";

// Handle root path
void handleRoot() {
    webServer.send(200, "text/html", htmlPage);
}

// Redirect all other requests to root
void handleNotFound() {
    webServer.sendHeader("Location", "/", true);
    webServer.send(302, "text/plain", "");
}

void setup() {
    // Start WiFi Access Point
    WiFi.softAP(ssid, password);
    delay(100); // Wait for AP to start

    // Get IP address of AP
    IPAddress apIP = WiFi.softAPIP();

    // Start DNS server to redirect all domains to captive portal
    dnsServer.start(DNS_PORT, "*", apIP);

    // Set up web server routes
    webServer.on("/", handleRoot);
    webServer.onNotFound(handleNotFound);

    // Start web server
    webServer.begin();
}

void loop() {
    dnsServer.processNextRequest();
    webServer.handleClient();
}