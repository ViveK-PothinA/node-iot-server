#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
 
//const char* ssid = "akhil999";
//const char* password = "akhil999";
const char* ssid = "Lenovo K50a40";
const char* password = "88888888";

int vcc=D1;
int pin = D3; // GPIO13
WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
  delay(10);
 
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  digitalWrite(vcc,HIGH);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  // server.begin();
  // Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
//   WiFiClient client = server.available();
//   if (!client) {
//     return;
//   }
 
//   // Wait until the client sends some data
//   Serial.println("new client");
//   while(!client.available()){
//     delay(1);
//   }
 
//   // Read the first line of the request
//   String request = client.readStringUntil('\r');
//   Serial.println(request);
//   client.flush();
 
//   // Match the request
 
//   int value = LOW;
//   if (request.indexOf("/LED=ON") != -1)  {
//     digitalWrite(pin, HIGH);
//     value = HIGH;
//   }
//   if (request.indexOf("/LED=OFF") != -1)  {
//     digitalWrite(pin, LOW);
//     value = LOW;
//   }
 
// // Set pin according to the request
// //digitalWrite(pin, value);
 
//   // Return the response
//   client.println("HTTP/1.1 200 OK");
//   client.println("Content-Type: text/html");
//   client.println(""); //  do not forget this one
//   client.println("<!DOCTYPE HTML>");
//   client.println("<html>");
//   client.println("<br><br>");
//   client.println("<H1><center>Welcome to SmartHome!</center></H1><Br>");
//   client.println("   <hr color= green>");
//   client.println("<center><a href=\"/LED=ON\"\"><button>Turn On </button></a>");
//   client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");  
//   client.print("LIGHTS ARE NOW: ");
 
//    if(value == HIGH) {
//     client.print("On");
//   } else {
//     client.print("Off");
//   }
 
//   client.println("  </center> <hr color= green>");
//   client.println("</html>");
  
 
//   delay(10);
//   Serial.println("Client disonnected");
//   Serial.println("");

  HTTPClient http;
  String getUrl, device, data;

  getUrl = "http://node-iot-server.herokuapp.com/getstatus/";

  device = "0";

  http.begin(getUrl);

  int httpCode = http.GET();
  String payload = http.getString();

  Serial.println(payload);

  if(payload == '0'){
    digitalWrite(pin, LOW);
  }
  else{
    digitalWrite(pin, HIGH);
  }


  http.end();
  delay(300 * 100); 

 
}