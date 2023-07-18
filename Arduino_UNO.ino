#include <SoftwareSerial.h>

SoftwareSerial ArduinoUNO(4, 5); 
//establisihing serial communication with pin 4 as reciever and pin 5 as transmitter

#define buzzer 7
#define freq 1200
#define in 14
#define out 19
#define relay 2

int count = 0;
int pinValue;

// IN() function - called when it detects incoming
void IN()
{

    count++;

    ArduinoUNO.print(count); // sending value to NodeMCU
    Serial.print(in);
    Serial.println(" " + count);
    tone(buzzer, freq, 500);

    noTone(buzzer);

    delay(1000);
}

// OUT() function - called when it detects outgoing
void OUT()
{
    if (count > 0)
        count--;

    Serial.print(out);
    Serial.println(" " + count);

    ArduinoUNO.print(count); // sending value to NodeMCU
    tone(buzzer, freq, 500);

    noTone(buzzer);

    delay(1000);
}

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Start");

    delay(2000);

    pinMode(in, INPUT);
    pinMode(out, INPUT);
    pinMode(relay, OUTPUT);

    ArduinoUNO.begin(9600); // starting serial communication 
    ArduinoUNO.print(count);
}

void loop()
{
    // put your main code here, to run repeatedly:

    while (ArduinoUNO.available() > 0)
    {

        pinValue = ArduinoUNO.parseInt();
        Serial.println(pinValue);

        if (pinValue == 20) // reset mode
        {
            digitalWrite(relay, HIGH);
            count = 0;
         
        }

        if (pinValue == 10) // admin mode
        {

            while (pinValue != 9)
            {
                Serial.println(pinValue);

                while (ArduinoUNO.available() > 0)
                {
                    pinValue = ArduinoUNO.parseInt();
                    if (pinValue == 1)
                    {
                        digitalWrite(relay, LOW);
                    }

                    if (pinValue == 0)
                    {
                        digitalWrite(relay, HIGH);
                    }
                }
            }
        }
    }

    if (digitalRead(in) == LOW) //incoming
      {
        IN();
      }

    if (digitalRead(out) == LOW) //outgoing
      {
        OUT();
      }

    if (count <= 0)
    {

        digitalWrite(relay, HIGH);
        Serial.println("off");
    }

    else
    {
        digitalWrite(relay, LOW);
        Serial.println("on");
    }
}
