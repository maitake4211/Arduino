#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);
void setup()
{
  BT.begin(9600);
}
char a;
void loop()
{
  if (BT.available()) {
    a = (BT.read());
    if (a == '1') {
      BT.println("HELLO &lt;Bluetooth&gt; WORLD!");
    }
    if (a == '2') {
      BT.println("2 is comming.");
    }
  }
}
