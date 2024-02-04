# define MOTOR_SP 100
# define INTERVAL 100

int A_IA = 10;
int A_IB = 9;
int B_IA = 5;
int B_IB = 6;

int A_ENCODER = 2;
int B_ENCODER = 3;

volatile int A_cnt = 0; // volatile : 메모리 관리를 위함
volatile int B_cnt = 0;
int A_speed = 0;
int B_speed = 0;
unsigned long oldTime = 0;
unsigned long newTime = 0;

int flag = 0;

// 인터럽트 하나당 함수 하나
void A_ISR() {
  A_cnt++;
}
void B_ISR() {
  B_cnt++;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(A_ENCODER, INPUT_PULLUP);
  attachInterrupt(INT0, A_ISR, FALLING);
  pinMode(B_ENCODER, INPUT_PULLUP);
  attachInterrupt(INT1, B_ISR, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'f') {
      A_speed = MOTOR_SP;
      B_speed = MOTOR_SP;
      flag = 1;
    }
    else if (c == 's') {
      A_speed = 0;
      B_speed = 0;
      flag = 0;
    }
  }

  newTime = millis();
  if (newTime-oldTime > INTERVAL) {
    oldTime = newTime;
    noInterrupts();
    Serial.print("cnt: ");
    Serial.print(A_cnt);
    Serial.print(", ");
    Serial.print(B_cnt);
    Serial.print(", ");
    Serial.print("err: ");
    Serial.println(A_cnt-B_cnt);

    if (flag) {
      if (A_cnt > B_cnt) B_speed++;
      else if (A_cnt < B_cnt) B_speed--;
    }

    A_cnt = 0; B_cnt = 0;
    analogWrite(A_IA, A_speed);
    analogWrite(A_IB, 0);
    analogWrite(B_IA, B_speed);
    analogWrite(B_IB, 0);
    interrupts();
  }

}
