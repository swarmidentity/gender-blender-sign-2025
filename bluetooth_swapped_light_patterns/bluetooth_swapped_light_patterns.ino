/***************************************************************************** 
 * GenderBlender - Bluetooth Swapped Light Patterns  *
 *****************************************************************************/
#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h> 
 #include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN        5
#define NUMPIXELS 738

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Replace with your desired SSID and password
const char* ssid = "GenderBlender";
const char* password = "";

const byte DNS_PORT = 53;
DNSServer dnsServer;

WebServer server(80);


String responseText = "No Command Yet Sent";

const char* htmlForm = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>GenderBlender</title>
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
    <h1>GenderBlender Sign Control</h12>
    
        </h3>Control Codes:</h3>
        <p> 
        <br>
        <h4>#[HexColor]</h4>
        <h5>Set all pixels to a single color</h5>
        Examples:<br>
        #FF0000 = Set all pixels to red<br>
        #00FF00 = Set all pixels to green<br>
        #0000FF = Set all pixels to blue<br>
        #FFFF00 = Set all pixels to yellow<br>
        #FF00FF = Set all pixels to purple<br>
        #00FFFF = Set all pixels to cyan<br>
        #FFFFFF = Set all pixels to white<br>
        <br>
        <br>
        <h4>R[start]-[end]-[hexColor]</h4>
        <h5>Set a range of pixels to a hex color</h5>
        Example:<br>
        R0-101-00FF00 = Set Pixels from 0 to 62 (the first letter G) to green
        <br><br>
        Letters on the sign are from pixel ranges:
        G = 0 - 62<br>
        E = 63 - 117<br>
        N = 118 - 175<br>
        D = 176 - 246<br>
        E = 247 - 296<br>
        R = 297 - 349<br>
        B = 350 - 421<br>
        L = 422 - 456<br>
        E = 457 - 507<br>
        N = 508 - 563<br>
        D = 564 - 631<br>
        E = 632 - 683<br>
        R = 684 - 737<br>
<br>

        <h4>B#</h4>
        <h5>Set the brightness to # (0 to 255)</h5>
        Ex: B255 = Full Brightness<br><br>

        <h4>F#</h4>
        <h5>Set Frequency Multiplier (1 to 1000) - higher = faster</h5>
        Example: F1 = Frequency Multiplier 1 = Slowest<br>
        F10 = Frequency Multiplier 10 = Medium Speed<br>
        F100 = Very Fast<br>
        F200 = Seizure<br>
        If it goes too high, the sign will bug out and pixels will set to solid colors
        <br>
        
        <h4>M#</h4>
        <h5>Set the current flash pattern to # (0 to 18)</h5>
        <br>Patterns:<br>
        M0 = SEPARATE_FLAG_PER_LETTER<br>
        M1 = RAINBOW<br>
        M2 = TRANS_FLAG_ANIMATED<br>
        M3 = NONBINARY_FLAG_ANIMATED<br>
        M4 = PAN_FLAG_ANIMATED<br>
        M5 = BISEXUAL_FLAG_ANIMATED<br>
        M6 = LESBIAN_FLAG_ANIMATED<br>
        M7 = GENDERQUEER_FLAG_ANIMATED<br>
        M8 = GENDERFLUID_FLAG_ANIMATED<br>
        M9 = AGENDER_FLAG_ANIMATED<br>
        M10 = INTERSEX_FLAG_ANIMATED<br>
        M11 = POLYSEXUAL_FLAG_ANIMATED<br>
        M12 = ASEXUAL_FLAG_ANIMATED<br>
        M13 = AROMANTIC_FLAG_ANIMATED<br>
        M14 = BIPOC_PRIDE_FLAG_ANIMATED<br>
        *note - I was trying to show the BIPOC stripes on the progress flag with this mode, but it kinda looks yellow instead. <br>
        M15 = TRANS_FLAG_STATIC<br>
        M16 = RAINBOW_IN_EACH_LETTER<br>
        M17 = ANIMATED_TRANS_FLAG_IN_EACH_LETTER<br>
        M18 = STATIC_TRANS_FLAG_IN_EACH_LETTER<br>
        <br>--Nai1s--<br>
    </p>
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
        reactToNewWifiCommand(userText);
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
  pixels.begin();
  initializeButton();
}

void loop() {
    dnsServer.processNextRequest();
    server.handleClient();
    checkButtonState();
    if (!isInDebugMode()) {
      switchBetweenLEDControlPatterns();
    }
    setAllPixelsBrightness(); // Apply brightness to all pixels
}





 