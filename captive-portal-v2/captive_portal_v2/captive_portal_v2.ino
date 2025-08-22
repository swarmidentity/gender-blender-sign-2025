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
const char* ssid = "Free Burner WiFi";
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
    <title>Why Are You Here?</title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            background: #222;
            color: #f5f5f5;
            font-family: monospace;
            margin: 0;
            padding: 0;
        }
        .container {
            max-width: 96vw;
            width: 100%;
            margin: 24px auto;
            padding: 16px;
            background: #333;
            border-radius: 8px;
            box-shadow: 0 0 12px #111;
        }
        pre.ascii {
            text-align: center;
            font-size: 5vw;
            margin-bottom: 18px;
            overflow-x: auto;
        }
        h1 {
            text-align: center;
            font-size: 7vw;
            margin-bottom: 12px;
        }
        .monologue {
            white-space: pre-wrap;
            font-size: 4vw;
            line-height: 1.5;
            margin-bottom: 12px;
            text-align: left;
        }
        .principles {
            font-size: 3vw;
            color: #aaa;
            text-align: center;
        }
        @media (min-width: 600px) {
            .container {
                max-width: 600px;
                padding: 24px;
            }
            pre.ascii {
                font-size: 16px;
            }
            h1 {
                font-size: 2em;
            }
            .monologue {
                font-size: 1.1em;
            }
            .principles {
                font-size: 0.95em;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <pre class="ascii">
⠀⠀⠀⠀⠀⠀⢱⣆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠈⣿⣷⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣧⠀⠀⠀
⠀⠀⠀⠀⡀⢠⣿⡟⣿⣿⣿⡇⠀⠀
⠀⠀⠀⠀⣳⣼⣿⡏⢸⣿⣿⣿⢀⠀
⠀⠀⠀⣰⣿⣿⡿⠁⢸⣿⣿⡟⣼⡆
⢰⢀⣾⣿⣿⠟⠀⠀⣾⢿⣿⣿⣿⣿
⢸⣿⣿⣿⡏⠀⠀⠀⠃⠸⣿⣿⣿⡿
⢳⣿⣿⣿⠀⠀⠀⠀⠀⠀⢹⣿⡿⡁
⠀⠹⣿⣿⡄⠀⠀⠀⠀⠀⢠⣿⡞⠁
⠀⠀⠈⠛⢿⣄⠀⠀⠀⣠⠞⠋⠀⠀
⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀
</pre>
        <h1>Why Are You Here?</h1>
        <div class="monologue">
You're at burning man.<br>
You came here to experience inclusion, immediacy and participation in the real world.<br>
Go talk to a real person; try a new experience; do something that you can't do on a screen.<br>
Stop hiding behind your camera, your followers or your memes; you have the rest of the year for that.<br>
Are you here to live - or to watch?<br>
-nai1s-<br>
        </div>
    </div>
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