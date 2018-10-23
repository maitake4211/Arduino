#define SRCLK   (5)
#define RCLK    (6)
#define SER     (7)

void setup() {
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK,  OUTPUT);
  pinMode(SER,   OUTPUT);
}

// 点灯パターン(1=点灯)
const uint8_t PATTERNS[] = {
  0b10000001,
  0b01000010,
  0b00100100,
  0b00011000,
  0b00100100,
  0b01000010
};

void loop() {
  
  int max_pattern = sizeof(PATTERNS)/sizeof(PATTERNS[0]);
  for (uint8_t i=0; i<max_pattern; i++) {
    // 8ビット分のデータをシフトレジスタへ送る
    shiftOut(SER, SRCLK, LSBFIRST, PATTERNS[i]); 

    // シフトレジスタの状態をストアレジスタへ反映させる
    digitalWrite(RCLK,  LOW);
    digitalWrite(RCLK,  HIGH);

    delay(200);
  }
}
