int light_time = 5000; //ミリ秒
int score = 0;
int game_count = 0;
int game_level = 1;
int select_bottm = 9;

void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);

  Serial.println("gameStart!!");
  delay(1000);
}

void loop() {
  if (game_count == 10 + 1) {     //ここでゲームの回数設定
    GameEnd_reset();
  }
  else if(game_count == 0){
    game_setting();
  }
  else {
    game_main();
  }
}



////ゲームのリセット確認
void GameEnd_reset() {
  Serial.print("game_score==");
  Serial.println(score);
  Serial.println("gameEND");
  score = 0;
  game_level = 0;
  light_time = 1000;
  Serial.println("Restart??");
  Serial.println("If restart now, push a greenbotan");
  while (1) {
    if (digitalRead(select_bottm) == HIGH) {     //終わる条件のボタン選択
      game_count = 0;
      score = 0;
      game_level = 0;
      light_time = 1000;
      break;
    }
  }

}



void game_setting(){
  int i;
  for(i = 0;i < 50;i++){
    if(digitalRead(select_bottm) == HIGH){     //ゲームレベルの選択ボタンの選択
      game_level++;
    }
    Serial.print("game_level===");
    Serial.println(game_level);
    delay(100);
  }
  game_count++;
}




void game_main() {
  int light_num;
  int i;
  randomSeed(analogRead(0));
  light_num = random(10, 13);

  digitalWrite(light_num, HIGH);
  for (i = 0; i < light_time; i++) {
    if (digitalRead(light_num - 4) == HIGH) {
      score++;
      break;
    }
    delay(1);
  }
  game_count++;
  digitalWrite(light_num, LOW);
  light_time -= game_level * 30; //ゲームが進むにつれて光る時間が減っていく
  delay(500);
}

