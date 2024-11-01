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

>![](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/DHT11%2BTM1637/TM1637_Lib.jpg?raw=true)

## 程式說明

[以下程式來源 DHT11.ino ]:[https://github.com/derricktsai0904/Arduino/blob/master/04%20NodeMCU/LEDControl/LED_Control.ino](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/Arduino%20LED%E9%9C%B9%E9%9D%82%E7%87%88/LED_Control.ino) "LED_Control.ino"
[以下程式來源 DHT11.ino ]
``` arduino
#include "DHT.h"
#include "TM1637.h"        //主程式需要程式庫 “TM1637.h”

#define DHTPIN 8   
#define DHTTYPE DHT11
#define CLK 3              //模組的CLK 接 Nano pin 3
#define DIO 2              //模組的DIO 接 Nano pin 2

TM1637 tm1637(CLK,DIO);    //宣告顯示晶片涵式庫
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
    }
  else {
    int dig1 = 0, dig2 = 0, dig3 = 0, dig4 = 0;    
    dig4 = (t / 10) % 10;
    dig3 = t % 10;

    dig2 = (h / 10)   % 10;
    dig1 = h % 10;
    
    tm1637.display(0,dig4);       //千位數  千位 百位 = 溫度
    tm1637.display(1,dig3);       //百位數

    tm1637.display(2,dig2);       //十位數 十位 個位 = 濕度
    tm1637.display(3,dig1);       //個位數
   }
  }
}

```
