<h1>Arduino LED 霹靂燈</h1>

## 準備材料 : 
>1. Arduino Nano板(CH340驅動程式.USB:MiniUSB) 
>2. MiniUSB 連接線 X 1 
>3. LED 五顆 
>4. 麵包板 X 1 
===

## 程式說明

[以下程式來源 LEDControl.ino ]:https://github.com/derricktsai0904/Arduino/blob/master/04%20NodeMCU/LEDControl/LEDControl.ino "ESP8266WIFI_LEDControl.ino"
[以下程式來源 LEDControl.ino ]
``` arduino
int speed = 20;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for(int i=8;i<=12;i++){ 
    pinMode(i,OUTPUT); 
  }
}

// the loop function runs over and over again forever
void loop() {
  for(int i=8;i<=12;i++){ 
      digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(speed);                       // wait for a second
      digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
      delay(speed);   
  }

  for(int i=12;i>=8;i--){ 
      digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(speed);                       // wait for a second
      digitalWrite(i, LOW);    // turn the LED off by making the voltage LOW
      delay(speed);   
  }
}

```
