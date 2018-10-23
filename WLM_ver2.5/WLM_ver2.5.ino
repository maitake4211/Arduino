/////////ライブラリ///////////
#include <OneWire.h>
#include <DallasTemperature.h>
#include "Adafruit_Si7021.h"
#include <Wire.h>
////////////////////////////////////////////////////////

//////////各種変数//////////////////////////////////////////////////////

////////water_temp//////////////
#define ONE_WIRE_BUS 10 // データ(黄)で使用するポート番号
#define SENSER_BIT 12      // 精度の設定bit(9から12までできる)
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

/////////temp_and_hum/////////////
Adafruit_Si7021 sensor = Adafruit_Si7021();

/////////照度///////////////////////////////
int BH1750_address = 0x23; // i2c Addresse(OPEN or connecting to GND)
//int BH1750_address = 0x5c; // i2c Addresse(connecting to Vcc)
byte buff[2];

////////////////////////////////////////////////////////////////////////


void setup() {
  Serial.begin(9600); //シリアルモニタ用のやつ

  sensors.setResolution(SENSER_BIT); //water_temp

  while (!Serial) {
    delay(10); //temp_and_humのセンサを見つける
  }

  ///////照度////
  Wire.begin();
  BH1750_Init(BH1750_address);
  pinMode(A4, INPUT);
  pinMode(A5, OUTPUT);

}



void loop() {
  water_temp();
  temp_and_hum();
  lax_senser();

}

/////////////////////////////////

void water_temp() {
  sensors.requestTemperatures();              // 水温取得要求
  Serial.println(sensors.getTempCByIndex(0));//水温の取得&シリアル送信
}



void temp_and_hum() {
  Serial.print("Humidity:    ");
  Serial.print(sensor.readHumidity(), 2); //湿度の取得&シリアル送信
  Serial.print("\tTemperature: ");
  Serial.println(sensor.readTemperature(), 2); //気温の取得&シリアル送信
}



void lax_senser() {
  float valf = 0;

  if (BH1750_Read(BH1750_address) == 2) {

    valf = ((buff[0] << 8) | buff[1]) / 1.2;

    if (valf < 0) {
      Serial.print("> 65535");
    }
    else {
      Serial.print((int)valf, DEC);
    }

    Serial.println(" lx");
  }

}

void BH1750_Init(int address) {
  Wire.beginTransmission(address);
  Wire.write(0x10); // 1 [lux] aufloesung
  Wire.endTransmission();
}

byte BH1750_Read(int address) {

  byte i = 0;
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  while (Wire.available()) {
    buff[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();
  return i;
}
