#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h> 

// Replace with your desired SSID and password
const char* ssid = "GenderBlenderSign";
const char* password = "";

const byte DNS_PORT = 53;
DNSServer dnsServer;

WebServer server(80);

String responseText = "Welcome! Please submit your message.";

const char* htmlForm = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Captive Portal</title>
</head>
<body>
    <h2>ESP32 Captive Portal</h2>
    <form action="/submit" method="POST">
        <label for="usertext">Enter text:</label>
        <input type="text" id="usertext" name="usertext">
        <input type="submit" value="Submit">
    </form>
    <p id="response">%RESPONSE%</p>
</body>
</html>
)rawliteral";

String processor(const String& var) {
    if (var == "RESPONSE") {
        return responseText;
    }
    return String();
}

void handleRoot() {
    String page = htmlForm;
    page.replace("%RESPONSE%", processor("RESPONSE"));
    server.send(200, "text/html", page);
}

// Redirect all other requests to root
void handleNotFound() {
    server.sendHeader("Location", "/", true);
    server.send(302, "text/plain", "");
}

void handleSubmit() {
    if (server.hasArg("usertext")) {
        String userText = server.arg("usertext");
        responseText = "ESP32 received: " + userText;
    } else {
        responseText = "No text received.";
    }
    handleRoot();
}

void setup() {

    WiFi.softAP(ssid, password);
    delay(100);

    IPAddress myIP = WiFi.softAPIP();
    dnsServer.start(DNS_PORT, "*", myIP);

    server.on("/", HTTP_GET, handleRoot);
    server.on("/submit", HTTP_POST, handleSubmit);
    server.onNotFound(handleNotFound);

    server.begin();
}

void loop() {
    dnsServer.processNextRequest();
    server.handleClient();
}