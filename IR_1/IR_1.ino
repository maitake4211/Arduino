/*  Infrared Remote Controller & IR Receiver demo program
  copy right John Yu
  connect VS1838B to  D10 see http://osoyoo.com/?p=144
*/
#include <IRremote.h>
int input_pin = 10; //set D10 as input signal pin
IRrecv irrecv(input_pin);
decode_results signals;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // enable input from IR receiver
}
void loop() {
  if(irrecv.decode(&signals)){
if (signals.value = 0xC101E57B) {
    digitalWrite(8,HIGH);
    delay(10);
    digitalWrite(8,LOW);
    delay(10);
  }
  Serial.println(signals.value, HEX);
  irrecv.resume();
}
}
