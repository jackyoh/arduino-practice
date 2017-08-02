#include <Wire.h>
#include <TEA5767Radio.h>
 
TEA5767Radio radio = TEA5767Radio();
 
void setup()
{
  Wire.begin();
  radio.setFrequency(89.9); // pick your own frequency
}

void loop()
{

  
}
