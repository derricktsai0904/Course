<h1>【練習題目 : 超音波距離感測 + 語音播放】</h1>

## 準備材料 : 
>1. Arduino Nano板(CH340驅動程式.USB:MicroUSB)
>2. MicroUSB 連接線 X 1
>3. HC-SR04 超音波感測器 X 1
>4. DFPlayer Mini 播放器 X 1
>5. 8Ω 0.5W 喇叭 X 1
>6. 1k ohm 電阻 X 2
>7. 麵包板 X 1
===

## Arduino Nano 腳位圖 

<img src="https://github.com/derricktsai0904/Arduino/blob/master/03%20Arduino%20%E9%80%B2%E9%9A%8E%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B/03%20%E8%AA%9E%E9%9F%B3%E6%92%AD%E6%94%BE/Arduino_NANO.jpg" width=600 height=400 />

## DFPlayer Mini 腳位圖 

<img src="https://github.com/derricktsai0904/Arduino/blob/master/03%20Arduino%20%E9%80%B2%E9%9A%8E%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B/03%20%E8%AA%9E%E9%9F%B3%E6%92%AD%E6%94%BE/DFPlayer_Mini.JPG" width=300 height=300 />

## HC-SR04 超音波感測器腳位圖

<img src="https://github.com/derricktsai0904/Course/blob/main/2025.09%20%E8%BF%91%E4%BB%A3%E9%9B%BB%E5%AD%90%E7%B3%BB%E7%B5%B1/11.%20%E8%B6%85%E9%9F%B3%E6%B3%A2.mp3%E6%92%AD%E6%94%BE/HCSR04.jpg" width=300 height=300 />

## 超音波距離感測+語音播放控制電路圖

<img src="https://github.com/derricktsai0904/Course/blob/main/2025.09%20%E8%BF%91%E4%BB%A3%E9%9B%BB%E5%AD%90%E7%B3%BB%E7%B5%B1/11.%20%E8%B6%85%E9%9F%B3%E6%B3%A2.mp3%E6%92%AD%E6%94%BE/playmp3.jpg"  width=800 height=600 />

## 相關函式 : 無
>1. Arduino.h
>2. SoftwareSerial.h
>3. DFRobotDFPlayerMini.h

## 程式說明

``` arduino
#include <DFMiniMp3.h> 

//使用軟體Serial
#include <SoftwareSerial.h>  
SoftwareSerial mySerial(2,3); // RX, TX

const int sw = 2000; // 定義播放雨音的長度 3 秒


// 宣告 notify class
//
class Mp3Notify; 

// 定義類型，其中第一個參數為決定用硬體Serial或軟體Serail
//
typedef DFMiniMp3<SoftwareSerial, Mp3Notify> DfMp3;  //如果用UNO板就用軟體Serail
//typedef DFMiniMp3<HardwareSerial, Mp3Notify> DfMp3;  //如果用Mega板就用硬體Serail

// 建立mp3物件
//
DfMp3 dfmp3(mySerial);

// 實作notification的類別，可以在不同的事件中，寫入想要進行的動作
// 若沒有特別要進行的處理，這裡不用修改
class Mp3Notify
{
public:
  static void PrintlnSourceAction(DfMp3_PlaySources source, const char* action)
  {
    if (source & DfMp3_PlaySources_Sd) 
    {
        Serial.print("SD Card, ");
    }
    if (source & DfMp3_PlaySources_Usb) 
    {
        Serial.print("USB Disk, ");
    }
    if (source & DfMp3_PlaySources_Flash) 
    {
        Serial.print("Flash, ");
    }
    Serial.println(action);
  }
  static void OnError([[maybe_unused]] DfMp3& mp3, uint16_t errorCode)
  {
    // 錯誤訊息
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }
  static void OnPlayFinished([[maybe_unused]] DfMp3& mp3, [[maybe_unused]] DfMp3_PlaySources source, uint16_t track)
  {
    Serial.print("Play finished for #");
    Serial.println(track);  
  }
  static void OnPlaySourceOnline([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "online");
  }
  static void OnPlaySourceInserted([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "inserted");
  }
  static void OnPlaySourceRemoved([[maybe_unused]] DfMp3& mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "removed");
  }
};


int const trigPin= 12;
int const echoPin= 11;
int Duration;
int Distance;
int first;

void setup() 
{
  Serial.begin(9600); //啟用監控視窗
  Serial.println("initializing...");
  
  dfmp3.begin();  //開始使用DFPlayer模組

  //重置DFPlayer模組，會聽到"波"一聲
  dfmp3.reset();

  //音量控制，0~30
  dfmp3.setVolume(30);

  Serial.println("Play Mp3 Voice...");

  // 播放MP3，參數就是第N首。如要播第一首MP3，參數就是1，第二首就是2

    // 超音波
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  digitalWrite(trigPin,LOW);
}

void loop() 
{
    digitalWrite(trigPin,HIGH); //發射超音波
    delay(1);
    digitalWrite(trigPin,LOW);
    Duration = pulseIn(echoPin,HIGH); //超音波發射到接收的時間
    Distance = Duration*0.034/2; //計算距離(cm)
    if ( Distance <= 15 && Distance!=0){
         Serial.print("play= HRS-04 =>");
         Serial.println(Distance);
         dfmp3.playMp3FolderTrack(1);
         delay(sw);
    }
    delay(10);
}

```






