/*  Infrared Remote Controller & IR Receiver demo program
  copy right John Yu
  connect VS1838B to  D10 see http://osoyoo.com/?p=144
*/
#include <IRremote.h>

const double front = 16718055.00;
const double back = 16730805.00;
const double right = 16734885.00;
const double left = 16716015.00;

#define input_pin 2
#define front_pin 12
#define back_pin 11
#define right_pin 9
#define left_pin 10
#define mote_time 500
double jizoku;

void mote(double i);

IRrecv irrecv(input_pin);
decode_results signals;
void setup()
{
  pinMode(front_pin, OUTPUT);
  pinMode(back_pin, OUTPUT);
  pinMode(right_pin, OUTPUT);
  pinMode(left_pin, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {
  double i = signals.value;

  if (irrecv.decode(&signals)) {
    if (i < 17000000.00) {
      Serial.println(i);
      mote(i);
    }

    else if (i > 17000000.00) {
      mote(jizoku);
    }
    delay(1);
    irrecv.resume(); // get the next signal
  }

}


void mote(double i) {

  if (i == front) {
    Serial.println("front");
    digitalWrite(front_pin, HIGH);
    digitalWrite(right_pin, HIGH);
    digitalWrite(left_pin, HIGH);
    delay(mote_time);
    digitalWrite(front_pin, LOW);
    digitalWrite(right_pin, LOW);
    digitalWrite(left_pin, LOW);    
    jizoku = front;
  }

  ////////////////////////////////
  //else if (i == back) {
  //Serial.println("back");
  //digitalWrite(back_pin, HIGH);
  //delay(500);
  //digitalWrite(back_pin, LOW);
  //jizoku = back;
  //}
  //////////////////////////////////

  else if (i == right) {
    Serial.println("right");
    digitalWrite(front_pin, HIGH);
    digitalWrite(right_pin, HIGH);
    delay(mote_time);
    digitalWrite(front_pin, LOW);
    digitalWrite(right_pin, LOW);
    jizoku = right;
  }

  else if (i == left) {
    Serial.println("left");
    digitalWrite(front_pin, HIGH);
    digitalWrite(left_pin, HIGH);
    delay(mote_time);
    digitalWrite(front_pin, LOW);
    digitalWrite(left_pin, LOW);
    jizoku = left;
  }
}

