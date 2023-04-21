int led1 = 9;
int led2 = 10;
volatile int counter = 0;
volatile int counter1 = 0;
volatile int counter2 = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), interruptHandler1, LOW );
  attachInterrupt(digitalPinToInterrupt(3), interruptHandler2,  LOW);
  Serial.begin(9600); // Baud rate 9600 bps
  Serial.println("Serial Monitor ready");
}

void loop() {
  if (counter % 2 == 0) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  delay(500);
  counter++;
}

void interruptHandler1() {
  counter1 = 0;
  while (counter1 < 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(100000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(100000);
    counter1++;
  }
}

void interruptHandler2() {
  
  counter2 = 0;
  while (counter2 < 5) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(100000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(100000);
    counter2++;
  }
}

  
