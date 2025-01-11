<h1>碩專一甲  J113252119 感測元件 期末作業</h1>

## 溫溼度警報器應用當溫度超過40度時，它會顯示當前溫度並啟動蜂鳴器 

## 電路準備材料 : 
>1. Arduino Nano板(CH340驅動程式.USB:MiniUSB) 
>2. MiniUSB 連接線 X 1 
>3. DHT11感測器
>4. TM1637 四位顯示器
>5. 蜂鳴器
>6. 麵包板 X 1 
===

## 電路圖
>![](https://github.com/J113252119/Arduino/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/%E6%9C%9F%E6%9C%AB%E8%80%83/%E6%9C%9F%E6%9C%AB%E4%BD%9C%E6%A5%AD%E9%9B%BB%E8%B7%AF%E5%9C%96.JPG?raw=true)

## Arduinot程式碼函式庫下載
>![](https://github.com/J113252119/Arduino/blob/main/2024.09感測元件/期中考/Arduinot%20TM1637程式碼函式庫.JPG?raw=true)

>![](https://github.com/J113252119/Arduino/blob/main/2024.09感測元件/期中考/Arduinot%20DHT11程式碼函式庫.JPG?raw=true)

## 程式說明
[以下程式來源 DHT11.ino ]:[https://github.com/derricktsai0904/Arduino/blob/master/04%20NodeMCU/LEDControl/LED_Control.ino](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/Arduino%20LED%E9%9C%B9%E9%9D%82%E7%87%88/LED_Control.ino) "LED_Control.ino"
[以下程式 ]
``` arduino
#include <DHT.h>
#include <TM1637Display.h>

// 定義引腳
#define DHTPIN 2       // DHT11資料引腳
#define DHTTYPE DHT11  // 定義DHT型號為DHT11
#define CLK 3          // TM1637時鐘引腳
#define DIO 4          // TM1637資料引腳
#define BUZZER 5       // 蜂鳴器引腳

// 初始化DHT和TM1637
DHT dht(DHTPIN, DHTTYPE);
TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  dht.begin();
  display.setBrightness(0x0f); // 設定顯示亮度
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // 檢查是否成功讀取
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // 顯示溫度在TM1637上
  display.showNumberDec(t, false);

  // 判斷溫度是否達到40度，並啟動蜂鳴器
  if (t >= 40) {
    digitalWrite(BUZZER, HIGH); // 開啟蜂鳴器
  } else {
    digitalWrite(BUZZER, LOW); // 關閉蜂鳴器
  }

  delay(2000); // 每2秒更新一次
}

