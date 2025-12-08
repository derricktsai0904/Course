<h1>【練習題目 : LED 控制】</h1>

## 準備材料 : 
>1. Arduino Nano 板(CH340驅動程式.USB:MicroUSB)
>2. MicroUSB 連接線 X 1
>3. LED 一顆
>4. 杜邦線數條
>5. 麵包板 X 1
===
 
>![](https://github.com/derricktsai0904/Arduino/blob/master/02%20Arduino%20%E5%9F%BA%E6%9C%AC%E6%84%9F%E6%B8%AC%E5%99%A8%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B/A.LED%E6%8E%A7%E5%88%B6/Arduino_LED.PNG?raw=true)

## LED控制電路圖

>![](https://github.com/derricktsai0904/Arduino/blob/master/02%20Arduino%20%E5%9F%BA%E6%9C%AC%E6%84%9F%E6%B8%AC%E5%99%A8%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B/A.LED%E6%8E%A7%E5%88%B6/Arduino_LED_Circuit.PNG?raw=true)

## 相關函式 : 無

## 程式說明

[以下程式來源 Blink.ino ]:https://github.com/derricktsai0904/Arduino/blob/master/02%20Arduino%20%E5%9F%BA%E6%9C%AC%E6%84%9F%E6%B8%AC%E5%99%A8%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B/A.LED%E6%8E%A7%E5%88%B6/Blink.ino "Blink.ino"
[以下程式來源 Blink.ino ]
``` arduino
int LED = 13; // 宣告 Arduino 連結 LED 腳位
void setup() {  // Arduino 啟始函式，只會執行一次
 pinMode(LED, OUTPUT); //設定腳位為輸出訊號
}  

void loop() { //Arduino 主要迴圈，執行無窮多次，直到關機為主
 digitalWrite(LED, HIGH);   // 設定 LED 亮
 delay(1000);               // 延遲一秒  
 digitalWrite(LED, LOW);    // 設定 LED 關
 delay(1000);               // 延遲一秒
}  

```

<h1>【練習題目 : 霹靂燈 控制】</h1><br>

## 電路圖說明 <br>
<img src="https://github.com/1104405103/Course/blob/main/%E5%85%89%E5%95%9F%E9%AB%98%E4%B8%AD/2025_%E9%9B%BB%E6%A9%9F%E4%B8%89%E5%BF%A0/2025.11.16/LED5.jpg" width=600 height=400 />

## 程式說明

[以下程式來源 LED_Control.ino ]:[https://github.com/derricktsai0904/Arduino/blob/master/04%20NodeMCU/LEDControl/LED_Control.ino](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/Arduino%20LED%E9%9C%B9%E9%9D%82%E7%87%88/LED_Control.ino) "LED_Control.ino"
[以下程式來源 LED_Control.ino ]
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


