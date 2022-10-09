#include <WiFi.h>

// Replace with your network credentials
const char * ssid = "OnePlus Nord2 5G";
const char * password = "oneplustwo";

// Set web server port number to 80
WiFiServer server(80);

// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current direction of motor rotation
String motor1dirn = "OFF";
String motor2dirn = "OFF";

// Assign output variables to GPIO pins
const int motor1p1 = 26;
const int motor1p2 = 27;
const int motor2p1 = 2;
const int motor2p2 = 4;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(motor1p1, OUTPUT);
  pinMode(motor1p2, OUTPUT);
  pinMode(motor2p1, OUTPUT);
  pinMode(motor2p2, OUTPUT);
  // Set outputs to LOW
  digitalWrite(motor1p1, LOW);
  digitalWrite(motor1p2, LOW);
  digitalWrite(motor2p1, LOW);
  digitalWrite(motor2p2, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) { // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client."); // print a message out in the serial port
    String currentLine = ""; // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) { // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c); // print it out the serial monitor
        header += c;
        if (c == '\n') { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the GPIOs on and off
            if (header.indexOf("GET /F") >= 0) {
              Serial.println("Forward");
              motor1dirn = "clock";
              motor2dirn = "counter-clock";
              digitalWrite(motor1p1, HIGH);
              digitalWrite(motor1p2, LOW);
              digitalWrite(motor2p1, LOW);
              digitalWrite(motor2p2, HIGH);

            } else if (header.indexOf("GET /B") >= 0) {
              Serial.println("Backward");
              motor1dirn = "counter-clock";
              motor2dirn = "clock";
              digitalWrite(motor1p1, LOW);
              digitalWrite(motor1p2, HIGH);
              digitalWrite(motor2p1, HIGH);
              digitalWrite(motor2p2, LOW);
            } else if (header.indexOf("GET /R") >= 0) {
              Serial.println("Right");
              motor1dirn = "counter-clock";
              motor2dirn = "counter-clock";
              digitalWrite(motor1p1, HIGH);
              digitalWrite(motor1p2, LOW);
              digitalWrite(motor2p1, HIGH);
              digitalWrite(motor2p2, LOW);
            } else if (header.indexOf("GET /L") >= 0) {
              Serial.println("Left");
              motor1dirn = "clock";
              motor2dirn = "clock";
              digitalWrite(motor1p1, LOW);
              digitalWrite(motor1p2, HIGH);
              digitalWrite(motor2p1, LOW);
              digitalWrite(motor2p2, HIGH);
            } else if (header.indexOf("GET /S") >= 0) {
              Serial.println("Stop");
              motor1dirn = "OFF";
              motor2dirn = "OFF";
              digitalWrite(motor1p1, LOW);
              digitalWrite(motor1p2, LOW);
              digitalWrite(motor2p1, LOW);
              digitalWrite(motor2p2, LOW);
            }
          }
        }
      }
    }
  }
}