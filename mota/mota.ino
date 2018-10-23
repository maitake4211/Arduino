#define PIN1 2
#define PIN1 3
#define PIN1 4
#define PIN1 5


void setup()
{
  //シリアル通信の初期化しシリアルモニタへ文字列を出力できるようにする　9600はボーレート(通信速度)
  Serial.begin(9600);
  Serial.println("プログラムが開始しました\n");

  //各ピンを出力モードにする
  pinMode(PIN1, OUTPUT);      //PIN1を出力モードにする
  pinMode(PIN2, OUTPUT);      //PIN2を出力モードにする
  pinMode(PIN3, OUTPUT);      //PIN3を出力モードにする
  pinMode(PIN4, OUTPUT);      //PIN4を出力モードにする
}

/*setupの後、終了するまで繰り返し呼び出される関数*/
void loop()
{
  float sleep_time;       //角ステップでのスリープ時間　5[ms]
  int i;
  for (sleep_time = 5; sleep_time > 0; sleep_time = sleep_time - 0.1) {
    Serial.println(sleep_time);
    for (i = 0; i < 100; i++) {

      //PIN1と2をHigh, PIN2と3をLowにしてステッピングモーターを1ステップ進める
      digitalWrite(PIN1, 1);
      digitalWrite(PIN2, 1);
      digitalWrite(PIN3, 0);
      digitalWrite(PIN4, 0);
      delay(sleep_time );     //スリープ

      //PIN2と3をHigh, PIN4と1をLowにしてステッピングモーターを1ステップ進める
      digitalWrite(PIN1, 0);
      digitalWrite(PIN2, 1);
      digitalWrite(PIN3, 1);
      digitalWrite(PIN4, 0);
      delay(sleep_time );     //スリープ

      //PIN3と4をHigh, PIN1と2をLowにしてステッピングモーターを1ステップ進める
      digitalWrite(PIN1, 0);
      digitalWrite(PIN2, 0);
      digitalWrite(PIN3, 1);
      digitalWrite(PIN4, 1);
      delay(sleep_time );

      //PIN4と1をHigh, PIN2と3をLowにしてステッピングモーターを1ステップ進める
      digitalWrite(PIN1, 1);
      digitalWrite(PIN2, 0);
      digitalWrite(PIN3, 0);
      digitalWrite(PIN4, 1);
      delay(sleep_time );

      //PIN1と2をHigh, PIN2と3をLowにしてステッピングモーターを1ステップ進める
      digitalWrite(PIN1, 1);
      digitalWrite(PIN2, 1);
      digitalWrite(PIN3, 0);
      digitalWrite(PIN4, 0);
      delay(sleep_time );     //スリープ

      //PIN2と3をHigh, PIN4と1をLowにしてステッピングモーターを1ステップ進める
      digitalWrite(PIN1, 0);
      digitalWrite(PIN2, 1);
      digitalWrite(PIN3, 1);
      digitalWrite(PIN4, 0);
      delay(sleep_time );     //スリープ

      //PIN3と4をHigh, PIN1と2をLowにしてステッピングモーターを1ステップ進める
      digitalWrite(PIN1, 0);
      digitalWrite(PIN2, 0);
      digitalWrite(PIN3, 1);
      digitalWrite(PIN4, 1);
      delay(sleep_time );

    }
  }
}
