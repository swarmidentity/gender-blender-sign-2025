# gender-blender-sign-2025


bluetooth_swapped_light_patterns is the main project, the rest are demo scripts.

I use:
https://play.google.com/store/apps/details?id=de.kai_morich.serial_bluetooth_terminal&hl=en_US

 as a bluetooth serial terminal to control the device.

 # LED debug script

bluetooth_led_counter lets you send an integer over Bluetooth and light the corresponding LED (for debug/alignment purposes)

 # BOM

ALITOVE WS2812B Addressable LED Strip Light 16.4ft 300 LEDs (x4)
 https://www.amazon.com/dp/B07FVR781Z

 20 Pairs SM JST 3 PIN Wire Connector Cable for WS2812B WS2811 SK6812 LED Strip Lights, 15cm 18 AWG
 https://www.amazon.com/dp/B0CH4KSQ6T

 Switch Mode Power Supply 300W 5V 60A Constant Voltage LED Driver 5VDC Rainproof Outdoor 110V AC to DC 5 Volt Transformer Converter (FX300-H1V5)
 https://www.amazon.com/dp/B07G7S44CW

ESP32 Controller
ESP-WROOM-32 ESP32 ESP-32S Development Board 2.4GHz Dual-Mode WiFi + Bluetooth Dual Cores Microcontroller Processor Integrated with Antenna RF AMP Filter AP STA Compatible with Arduino IDE (3PCS)
https://www.amazon.com/ESP-WROOM-32-Development-Microcontroller-Integrated-Compatible/dp/B08D5ZD528/

 # Wiring

Power supply connections (+/- 5v)
LED PWM Control through Pin 5
Common ground from power supply to ESP32 ground pin
USB power for ESP32


# Arduino programmer setup
https://github.com/espressif/arduino-esp32

using DOIT ESP32 DEVKIT v1