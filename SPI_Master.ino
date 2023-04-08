#include <Arduino.h>

#define SCK  2    // chân SCK
#define MOSI 3   // Chân MOSI
#define SS   4     // Chân SS
#define MISO 5   // chân MISO

void SPI_Soft_init();// chương trình khởi tạo SPI
void Clock();// chương trình tạo 1 xung clock
void SPI_Soft_Transmit(uint8_t mData);// chương trình gửi 1 byte
uint8_t SPI_Soft_Receive();// chương trình nhận về 1 byte

void Delay_us(unsigned int microseconds) {
  delayMicroseconds(microseconds);
}

void setup() {
  digitalWrite(SS, LOW); 
  // Khởi tạo chân GPIO
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SS, OUTPUT);
  pinMode(MISO, INPUT);
  Serial.begin(9600); // initialize Serial Monitor
}

void loop() {
  // Gửi dữ liệu đi
  SPI_Soft_Transmit(0x72);
  Serial.println("Sent data");

  // Nhận dữ liệu
  uint8_t receivedData = SPI_Soft_Receive();
  Serial.print("Received data: ");
  Serial.println(receivedData, HEX);

  delay(5000);
}



void Clock(){
  digitalWrite(SCK, HIGH);
  Delay_us(5); 
  digitalWrite(SCK, LOW);
  Delay_us(5); 
}

void SPI_Soft_Transmit(uint8_t mData){ 
  uint8_t i = 0, x = 0;   
  digitalWrite(SS , LOW);  
  for(i = 0; i < 8; i++){ 
    x = mData&0x80; // đưa bit cần truyền lên chân MOSI 
    if(x>0)
        digitalWrite(MOSI, HIGH);  
    else
        digitalWrite(MOSI, LOW);  
      Clock(); // phát 1 xung clock gửi dữ liệu đi  
       Serial.print("send data: ");
      Serial.println( x , BIN); 
      mData=mData<<1; // dịch dữ liệu cần gửi lên 1 bits 
   }  
  digitalWrite(SS , HIGH); //Đã gửi xong,đưa chân SS lên mức 1
  Serial.print("complete send data: ");
  
}

uint8_t SPI_Soft_Receive(){  
  uint8_t _data=0x00, i=0;  
  while(i<8){ 
      Serial.print("Received data: ");
  Serial.println(_data, HEX);    
    _data = _data<<1;       // dịch dữ liệu lên 1 bit     
    _data = _data | digitalRead(MISO);    //đọc chân MISO
    Clock();                // phát một xung clock để đọc bit tiếp theo  
  i++;
}
  return _data;             // trả về dữ liệu đọc được 
}
  
