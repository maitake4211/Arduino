int light_time = 1000; //ミリ秒
int score = 0;
int game_count = 0;

void setup() {
  Serial.begin(9600);

  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);

  randomSeed(analogRead(0));
  Serial.println("gameStart!!");
}

void loop() {

  if (game_count == 5) {     //ここでゲームの回数設定
    GameEnd_reset();
  }
  else {
    game_main();
  }
}



////ゲームのリセット確認
void GameEnd_reset() {
  Serial.print("game_score");
  Serial.println(score);
  Serial.println("gameEND");
  score = 0;
  Serial.println("restart??");
  Serial.println("If restart now, push a greenbotan");
  while (1) {
    if (digitalRead( ??? ) == HIGH) {     //終わる条件のボタン選択
      break;
    }
  }

}



void game_main() {
  int light_num = random(6, 9);
  int i;
  light_time -= game_count * 100; //ゲームが進むにつれて光る時間が減っていく

  digitalWrite(light_num, HIGH);
  for (i = 0; i < light_time; i++) {
    if (digitalRead(light_num + 4) == HIGH) {
      score++;
      break;
    }
    delay(1);
  }
  game_count++;
  digitalWrite(light_num, LOW);
}

