#include <Bridge.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <YunClient.h>
#include <YunServer.h>

//byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0x39, 0xA7 };
IPAddress server(52,11,215,248);//AWS
//IPAddress ip(192, 168, 0, 177);//static ip for router
//EthernetClient client;
YunClient client;

 
// constants won't change. Used here to set a pin number :
const int ledPin =  13;      // the number of the LED pin

// Variables will change :
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)


int fsrPin = 0;
int fsrReading;


void setup() {
// Open serial communications and wait for port to open:
Bridge.begin();
Serial.begin(9600);
pinMode(ledPin, OUTPUT);

//Ethernet.begin(mac, ip);
delay(10000); // give the Ethernet shield a second to initialize:
}
 
void loop(void) {
  //delay(60000); 
  unsigned long currentMillis = millis();
  fsrReading = analogRead(fsrPin);  
  Serial.print("Analog reading = ");
  Serial.print(fsrReading);     // the raw analog reading
 
  // Sensor threshholds, qualitatively determined
  if (fsrReading < 10) {
    Serial.println(" - No pressure");
    } else if (fsrReading < 200) {
    Serial.println(" - Light touch");
  } else if (fsrReading < 500) {
    Serial.println(" - Light squeeze");
  } else if (fsrReading < 800) {
    Serial.println(" - Medium squeeze");
  } else {
   Serial.println("connecting");
   client.connect("52.11.215.248",80);
   client.print("GET /cps/cps.php?s=1&r="); //must be print not println
   client.println(fsrReading);
   client.println(" HTTP/1.1");
   client.println("Host: 52.11.215.248");
   client.println("");
   client.stop();
   digitalWrite(ledPin, HIGH);
   delay(60000);
   digitalWrite(ledPin, LOW);
   
   }
   
  }

  

