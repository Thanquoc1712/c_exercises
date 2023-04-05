#include <Arduino.h>
#include <esp32-hal-timer.h>

hw_timer_t *timer = NULL; // Khai báo biến timer

void IRAM_ATTR onTimer() {
  static bool ledState = false;
  digitalWrite(2, ledState); // Điều khiển đèn LED trên chân GPIO2
  ledState = !ledState;
    Serial.println("Timer Interrupt");

}

void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT); // Khai báo  GPIO2 điều khiển đèn LED

  timer = timerBegin(0, 80, true); // Tạo một timer với số thứ tự 0, chia tỷ lệ tần số 80
  timerAttachInterrupt(timer, &onTimer, true); // Gắn hàm ngắt với timer
  timerAlarmWrite(timer, 2000000, true); // Thiết lập thời gian delay 2 giây
  timerAlarmEnable(timer); // Bật timer
}

void loop() {
}
