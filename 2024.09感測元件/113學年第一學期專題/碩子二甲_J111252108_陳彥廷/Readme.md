
<h1>感測元件期末報告 - 監測環境溫度與音頻警報系統</h1>

## 準備材料 : 

>1. Arduino Nano板(CH340驅動程式.USB:MiniUSB) x 1
>2. MiniUSB 連接線 x 1
>3. DFPlayer mini  x 1 (TX -> D11 . RX -> D12 . VCC -> 5V . GND -> GND)
>4. DHT11 感測器 x 1 (VCC -> 5V . GND -> GND . DAT -> D4)
>5. TM1637 四位顯示器x 1 (CLK -> D2 . DIO -> D3 . VCC -> 5v . GND -> GND)
>6. 喇叭 x 1 
>7. 麵包板 x 1 
>8. LED x 1

## 電路圖
>![](https://github.com/Ham-ch/TEST1/blob/main/CODE1/%E8%9E%A2%E5%B9%95%E6%93%B7%E5%8F%96%E7%95%AB%E9%9D%A2%202024-12-28%20140151.png)

## 引入函式庫

>![](https://github.com/Ham-ch/TEST1/blob/main/CODE1/141659.png)
>![](https://github.com/Ham-ch/TEST1/blob/main/CODE1/141737.png)

## 流程圖

>![](https://github.com/Ham-ch/TEST1/blob/main/CODE1/243640.jpg)

## 實作感應到溫度高於20度

>![](https://github.com/Ham-ch/TEST1/blob/main/CODE1/1.jpg)

## 實作影片

<a href= "https://www.youtube.com/shorts/32zJrRhXVW4">
<img src= "https://i.ytimg.com/vi/32zJrRhXVW4/oar2.jpg?sqp=-oaymwEoCJUDENAFSFqQAgHyq4qpAxcIARUAAIhC2AEB4gEKCBgQAhgGOAFAAQ==&rs=AOn4CLA1kXOIQcs2IWTwRVDh0-mNiFULkA/0.jpg" width=480 height=480></a>

## 程式碼

``` arduino

#include <DHT.h>
#include <TM1637Display.h>
#include <SoftwareSerial.h>
#include <DFMiniMp3.h>     // 引入 DFMiniMp3 播放器程式庫

// 定義 DHT11 感測器
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// 定義 TM1637 四位顯示器
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);

// 定義紅色 LED
#define LED_RED 8

// 定義 DFPlayer Mini MP3播放系統
SoftwareSerial mp3(11, 12); // RX, TX
class Mp3Notify;
typedef DFMiniMp3<SoftwareSerial, Mp3Notify> DfMp3;  // 定義 MP3 播放器物件類型
DfMp3 dfmp3(mp3);   // 建立 MP3 播放器物件，使用 mySerial 與模組溝通

// 定義 Mp3Notify 類別，用於處理 MP3 播放器的回呼事件
class Mp3Notify {
public:
  // 列印來源 (SD, USB, Flash) 和行為 (例如插入、移除)
  static void PrintlnSourceAction(DfMp3_PlaySources source, const char *action) {
    if (source & DfMp3_PlaySources_Sd) {   // 若來源為 SD 卡
      Serial.print("SD Card, ");
    }
    if (source & DfMp3_PlaySources_Usb) {  // 若來源為 USB
      Serial.print("USB Disk, ");
    }
    if (source & DfMp3_PlaySources_Flash) { // 若來源為 Flash 記憶體
      Serial.print("Flash, ");
    }
    Serial.println(action);  // 列印動作，例如 online, inserted 等
  }
  
  // 處理錯誤訊息的回呼函式
  static void OnError(DfMp3 &mp3, uint16_t errorCode) {
    Serial.print("Com Error ");  // 印出錯誤代碼
    Serial.println(errorCode);
  }
  
  // 播放完成時的回呼函式
  static void OnPlayFinished(DfMp3 &mp3, DfMp3_PlaySources source, uint16_t track) {
    Serial.print("Play finished for #");  // 播放完成後印出軌道號碼
    Serial.println(track);
  }

  // 音源上線時觸發
  static void OnPlaySourceOnline(DfMp3 &mp3, DfMp3_PlaySources source) {
    PrintlnSourceAction(source, "online");
  }

  // 音源插入時觸發
  static void OnPlaySourceInserted(DfMp3 &mp3, DfMp3_PlaySources source) {
    PrintlnSourceAction(source, "inserted");
  }

  // 音源移除時觸發
  static void OnPlaySourceRemoved(DfMp3 &mp3, DfMp3_PlaySources source) {
    PrintlnSourceAction(source, "removed");
  }
};

void setup() {
  // 初始化序列埠
  Serial.begin(9600);
  dfmp3.begin();               // 初始化 DFPlayer Mini
  dfmp3.setVolume(13);         // 設置音量（範圍：0-30）
  dfmp3.playMp3FolderTrack(1); // 播放 MP3 資料夾中的第一首音樂

  // 初始化 DHT11 感測器
  dht.begin();

  // 初始化 TM1637 四位顯示器
  display.setBrightness(0x0f);

  // 初始化 LED
  pinMode(LED_RED, OUTPUT);

  // 初始化 DFPlayer Mini
  //dfmp3.playMp3FolderTrack(1); // 選擇第一首音檔作為警報音效
}

void loop() {
  // 讀取溫
  float temp = dht.readTemperature();
  //float hum = dht.readHumidity();

  // 顯示溫度
  if (!isnan(temp)) {
    display.showNumberDec(temp, false);
  } else {
    display.showNumberDec(0, false); // 當感測器失敗時顯示 0
  }

  // 控制紅色 LED 和播放音效
  if (temp > 27) { // 如果温度大于 27°C
    digitalWrite(LED_RED, HIGH);  // LED 亮起
    playAlarm(2); // 播放第二首警報音效
  } else if (temp >= 20) { // 如果温度大于 20°C 且小于等于 27°C
    digitalWrite(LED_RED, HIGH);  // LED 亮起 
    playAlarm(1); // 播放第一首警報音效
  } else {
    digitalWrite(LED_RED, LOW);  // LED 熄滅
  }

  delay(5000); // 每10秒更新一次
}

// 修改 playAlarm 函數，允許動態選擇音軌
void playAlarm(uint8_t track) {
  dfmp3.playMp3FolderTrack(track); // 播放指定的音軌
}


void sendCommandToMP3(byte command, byte parameter) {
  byte buffer[10] = {0x7E, 0xFF, 0x06, command, 0x00, 0x00, parameter, 0xFE, 0xEF};
  for (byte i = 0; i < 10; i++) {
    mp3.write(buffer[i]);
  }
}
