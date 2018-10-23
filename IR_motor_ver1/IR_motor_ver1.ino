#define PIN1 2
#define PIN1 3
#define PIN1 4
#define PIN1 5




#include <IRremote.h>

int input_pin = 13; //set D10 as input signal pin
IRrecv irrecv(input_pin);
decode_results signals;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // enable input from IR receiver
}

void motor(int n){
  int sleep_time = 5;
  if(n == 1){
    digitalWrite(PIN1, 1);    
    digitalWrite(PIN2, 0);
    digitalWrite(PIN3, 0);
    digitalWrite(PIN4, 1);
    delay(sleep_time ); 

    digitalWrite(PIN1, 1);    
    digitalWrite(PIN2, 1);
    digitalWrite(PIN3, 0);
    digitalWrite(PIN4, 0);
    delay(sleep_time ); 

    digitalWrite(PIN1, 0);    
    digitalWrite(PIN2, 1);
    digitalWrite(PIN3, 1);
    digitalWrite(PIN4, 0);
    delay(sleep_time ); 

    digitalWrite(PIN1, 0);    
    digitalWrite(PIN2, 0);
    digitalWrite(PIN3, 1);
    digitalWrite(PIN4, 1);
    delay(sleep_time ); 
  }
}

void loop() {
  double i = signals.value;
  if (irrecv.decode(&signals)) {
    Serial.println(i);
    if(i = 16718055.00){
      motor(1);
    }
    delay(100);
    irrecv.resume(); // get the next signal
  }
}

