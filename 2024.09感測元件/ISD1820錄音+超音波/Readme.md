<h1>ISD1820 錄音加超音波電路</h1>

## 準備材料 : 
>1. Arduino Nano板(CH340驅動程式.USB:MiniUSB) 
>2. MiniUSB 連接線 X 1
>3. 超音波感測器 HCSR04 X 1
>4. ISD1820 錄音播放模組
>5. 喇叭
>6. 麵包板 X 1 
===

## 電路圖
>![](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/ISD1820%E9%8C%84%E9%9F%B3%2B%E8%B6%85%E9%9F%B3%E6%B3%A2/ISD%2BHCSR04.jpg?raw=true)


## 下載函式庫
>![](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/ISD1820%E9%8C%84%E9%9F%B3%2B%E8%B6%85%E9%9F%B3%E6%B3%A2/HCSR04.jpg?raw=true)


## 程式說明
https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/ISD1820%E9%8C%84%E9%9F%B3%2B%E8%B6%85%E9%9F%B3%E6%B3%A2/HCSR04.ino

[以下程式來源 DHT11.ino ]:[https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/ISD1820%E9%8C%84%E9%9F%B3%2B%E8%B6%85%E9%9F%B3%E6%B3%A2/HCSR04.ino](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/ISD1820%E9%8C%84%E9%9F%B3%2B%E8%B6%85%E9%9F%B3%E6%B3%A2/HCSR04.ino) "HCSR04.ino"
[以下程式來源 HCSR04.ino ]
``` arduino
#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(11, 12);  // Initialize sensor that uses digital pins 13 and 12.

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
    pinMode(10, OUTPUT);
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    int x = distanceSensor.measureDistanceCm();
    Serial.println(x);
    if( (x < 15) && (x != -1 )){
       digitalWrite(10, HIGH);
       delay(10);
       digitalWrite(10, LOW);
       delay(10);
       Serial.println("hit....");
    }
    delay(500);
}

```
