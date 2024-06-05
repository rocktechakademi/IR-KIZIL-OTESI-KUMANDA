#include <IRremote.h>

int kumandaPin = 2;
int sariledPin = 8;
int yesilledPin = 9;


IRrecv kumanda(kumandaPin);
decode_results sonuclar;

void setup()
{
  kumanda.enableIRIn();
  pinMode(sariledPin, OUTPUT);
  pinMode(yesilledPin, OUTPUT);
  
  Serial.begin(9600);
}
 
void loop()
{
  if(kumanda.decode(&sonuclar))
  {
    Serial.print("Tuş kodu: ");
    Serial.println(sonuclar.value, HEX);
    kumanda.resume();
  }

  delay(1000);
}
