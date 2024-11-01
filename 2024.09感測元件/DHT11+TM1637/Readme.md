<h1>DHT11溫濕度 + TM1637四位顯示器 電路</h1>

## 準備材料 : 
>1. Arduino Nano板(CH340驅動程式.USB:MiniUSB) 
>2. MiniUSB 連接線 X 1 
>3. DHT11感測器
>4. TM1637 四位顯示器
>5. 麵包板 X 1 
===

## 電路圖
>![](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/DHT11%2BTM1637/TM1637%E9%9B%BB%E8%B7%AF.jpg?raw=true)


## 下載函式庫
>![](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/DHT11%E6%BA%AB%E6%BF%95%E5%BA%A6/DHT11Lib.jpg?raw=true)

## 程式說明

[以下程式來源 DHT11.ino ]:[https://github.com/derricktsai0904/Arduino/blob/master/04%20NodeMCU/LEDControl/LED_Control.ino](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/Arduino%20LED%E9%9C%B9%E9%9D%82%E7%87%88/LED_Control.ino) "LED_Control.ino"
[以下程式來源 DHT11.ino ]
``` arduino
#include "DHT.h"
#define DHTPIN 8   
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
    }
  else {
    Serial.print("Temp=");
    Serial.print(t);
    Serial.println(" *C");
    Serial.println("Temp=");

    Serial.print("Humidity=");
    Serial.print(h);
    Serial.println("% ");
    delay(500);
   }
  }
}

```
