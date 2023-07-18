#define BLYNK_TEMPLATE_ID "TMPLU7TNh7Dx"
#define BLYNK_DEVICE_NAME "Exp Project"
#define BLYNK_AUTH_TOKEN  "ZjL6_H-mNGoKXBmmDxjNV9H89aZ-IEt6"

#include <SoftwareSerial.h>
#include<ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const char* ssid = "Motorola Edge 20 Fusion"; //Enter SSID
const char* password = "00000000"; //Enter Password
char auth[] = "ZjL6_H-mNGoKXBmmDxjNV9H89aZ-IEt6";
BlynkTimer timer;

SoftwareSerial NodeMCU(5, 4);

int flags = 0;

//void blinkLedWidget(){
BLYNK_WRITE(V1)
{ 
   
  

  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

  if (pinValue == 1)
  {
    digitalWrite(LED_BUILTIN, LOW);
    flags = 1;
    Blynk.virtualWrite(V2, flags);
  }

  else if (pinValue == 0)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    flags = 0;
      Blynk.virtualWrite(V2, flags);

  }

  //Serial.print("V1 button value is: "); // printing value to serial monitor
  //Serial.println(pinValue);

}

//char c;
//String dataIN;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("*");
  }

  Serial.println("");
  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.print(WiFi.localIP());// Print the IP address


  Blynk.begin(auth, ssid, password);
  
  pinMode(LED_BUILTIN, OUTPUT);
  NodeMCU.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//  int i = 2;
//  NodeMCU.print(i);
//  delay(1000);

//  while (NodeMCU.available() > 0)
//  {
//     
//    int j = NodeMCU.parseInt();
//    
//
//    Serial.println(j);
//   if(flags == 0)
//   {
//    if (j == 0)
//      digitalWrite(LED_BUILTIN, LOW);
//
//    if (j == 1)
//      digitalWrite(LED_BUILTIN, HIGH);
//   }

//       i = 3;
//  NodeMCU.print(i);
//  delay(1000);

    Blynk.run();
  //}

 


  //   while (NodeMCU.available() > 0)
  //  {
  //    c = NodeMCU.read();
  //
  //    if ( c == '\n')
  //      {break;}
  //
  //    else
  //      {dataIN += c;}
  //  }
  //
  //  if (c == '\n')
  //  {
  //    Serial.println(dataIN);
  //    NodeMCU.print("Hii \n");
  //    c = 0;
  //    dataIN = "";
  //  }
}
