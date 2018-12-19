#include <TinyWireM.h>
#include <VL53L0X.h>

VL53L0X sensor;

void setup()
{
  TinyWireM.begin();

  sensor.init();
  sensor.setTimeout(500);

  sensor.startContinuous();
  pinMode(3,OUTPUT);
}

void loop()
{
  int val = sensor.readRangeContinuousMillimeters();
  if(val<160) digitalWrite(3,LOW);
  else digitalWrite(3,HIGH);
  delay(100);
}
