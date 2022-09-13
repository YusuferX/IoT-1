#include <dht.h>

dht DHT;

#define DHT11_PIN 7


int ledPin = 11;
int temp1;
int temp2;
bool firstCall;
bool secondCall;
void setup()
{
  Serial.begin(9600);
 pinMode(ledPin, OUTPUT);

}

void loop()
{
    test2();
    test();
    checkTemp();
}

void checkTemp()
{
  if(secondCall)
  {
      if(temp1 = temp2)
  {
     Serial.print("Didn't change ");
     digitalWrite(ledPin, HIGH);
     delay(1000);
      secondCall = false;
  }
  else
  {
    if(temp1 != temp2)
  {
     Serial.print("Changed ");
     digitalWrite(ledPin, LOW);
     delay(1000);
     secondCall = false;
  }
  }
  


  }
}
void test()
{
  if( !secondCall)
  {
     int chk = DHT.read11(DHT11_PIN);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    temp1 = DHT.humidity;
    delay(3000);
    firstCall = true;
  }

}

void test2()
{
  if(firstCall)
  {
    int chk = DHT.read11(DHT11_PIN);
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    delay(4000);
    temp2 = DHT.humidity;
    
    secondCall = true;
    firstCall = false;
    
  }
  
}
 
    
