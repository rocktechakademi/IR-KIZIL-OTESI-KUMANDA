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

    if(sonuclar.value == 0xFF10EF)
    {
      digitalWrite(sariledPin, HIGH);
      Serial.print("Sari Led Yandi  \n");
    }
    if(sonuclar.value == 0xFF5AA5)
    {
      digitalWrite(yesilledPin, HIGH);
       Serial.print("Yesil Led Yandi  \n");
    }

    if(sonuclar.value == 0xFF9867)
    {
      digitalWrite(sariledPin, LOW);
      digitalWrite(yesilledPin, LOW);
       Serial.print("Ledler sondu  \n");
    }
    if(sonuclar.value == 0xFF38C7)
    {
      digitalWrite(sariledPin, HIGH);
      digitalWrite(yesilledPin, HIGH);
       Serial.print("Ledler Yandi  \n");
    }
  }

  delay(100);
}
