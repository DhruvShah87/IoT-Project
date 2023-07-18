#include <SoftwareSerial.h>

SoftwareSerial ArduinoUNO(10, 11);

//char c;
//String dataIN;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  ArduinoUNO.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int a = 0;
  ArduinoUNO.print(a);
  delay(1000);

//  while (ArduinoUNO.available() > 0)
//  {
//     int a = 0;
//  ArduinoUNO.print(a);
//  delay(1000);
//  
//    int b = ArduinoUNO.parseInt();
//    Serial.println(b);
//
//    if (b == 2)
//      digitalWrite(LED_BUILTIN, LOW);
//
//    if (b == 3)
//      digitalWrite(LED_BUILTIN, HIGH);
//
//        a = 1;
//  ArduinoUNO.print(a);
//  delay(1000);
//  }

  a = 1;
  ArduinoUNO.print(a);
  delay(1000);


  //  while (ArduinoUNO.available() > 0)
  //  {
  //    c = ArduinoUNO.read();
  //
  //    if ( c == '\n')
  //      {break;}
  //
  //    else
  //     { dataIN += c;}
  //  }
  //
  //  if (c == '\n')
  //  {
  //    Serial.println(dataIN);
  //    c = 0;
  //    dataIN = "";
  //  }
}
