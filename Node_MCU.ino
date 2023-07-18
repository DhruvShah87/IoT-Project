#define BLYNK_TEMPLATE_ID "TMPLU7TNh7Dx"
#define BLYNK_DEVICE_NAME "Exploration Project 32"
#define BLYNK_AUTH_TOKEN "ZjL6_H-mNGoKXBmmDxjNV9H89aZ-IEt6"

#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

const char *ssid = "Motorola Edge 20 Fusion"; // Enter SSID
const char *password = "00000000";            // Enter Password
char auth[] = "ZjL6_H-mNGoKXBmmDxjNV9H89aZ-IEt6"; // auth token - used to identify dashboard

BlynkTimer timer;

SoftwareSerial NodeMCU(5, 4); 
// establisihing serial communication with pin 5 as reciever and pin 4 as transmitter

int flags;
int count = 0;
int max_count = 0;
int pinValue;
int reset_count = 0;

// Reading from Virtual Pin V1
BLYNK_WRITE(V1)
{

    int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
    Serial.println(pinValue);
    NodeMCU.print(pinValue);
}

// Reading from Virtual Pin V4
BLYNK_WRITE(V4)
{
    int i = 0;
    flags = param.asInt();
    if (flags == 1)
        i = 10;

    if (flags == 0)
        i = 9;

    Serial.println(i);

    NodeMCU.print(i);
}

// Reading from Virtual Pin V5
BLYNK_WRITE(V5)
{

    reset_count = param.asInt();
    if (reset_count == 1)
    {
        count = 0;
        max_count = 0;
        Blynk.virtualWrite(V2, 0);
        Blynk.virtualWrite(V3, 0);
        NodeMCU.print(20);
    }
}

void myTimer()
{
    Blynk.virtualWrite(V2, count);

    if (count > max_count)
    {
        max_count = count;
        Blynk.virtualWrite(V3, max_count);
    }
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    WiFi.begin(ssid, password); // connecting with WiFi
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print("*");
    }

    Serial.println("");
    Serial.println("WiFi connection Successful");
    Serial.print("The IP Address of ESP8266 Module is: ");
    Serial.print(WiFi.localIP()); // Print the IP address

    Blynk.begin(auth, ssid, password); // connecting with blynk
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V3, 0);

    timer.setInterval(1000L, myTimer); // timer function
    NodeMCU.begin(9600); // starting serial communication 
}

void loop()
{
    // put your main code here, to run repeatedly:

    while (NodeMCU.available() > 0)
    {
        count = NodeMCU.parseInt();
        Serial.println(count);

        Blynk.run();
        timer.run();
    }
    Blynk.run();
}
