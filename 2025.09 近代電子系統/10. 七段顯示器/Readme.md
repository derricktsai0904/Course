

<h1>【練習題目 : 七段顯示器】</h1>

## 準備材料 : 
>1. Arduino Nano 板(CH340驅動程式.USB:MiniUSB)
>2. MicroUSB 連接線 X 1
>3. 七段顯示器(共陰極) X 1
>4. 杜邦線數條
>5. 麵包板 X 1
===
 
>![](https://github.com/derricktsai0904/Arduino/blob/master/02%20Arduino%20%E5%9F%BA%E6%9C%AC%E6%84%9F%E6%B8%AC%E5%99%A8%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B/%E4%B8%83%E6%AE%B5%E9%A1%AF%E7%A4%BA%E5%99%A8/Arduino_Seven_M.JPG?raw=true)

## 七段顯示器電路圖

>![](https://github.com/derricktsai0904/Arduino/blob/master/02%20Arduino%20%E5%9F%BA%E6%9C%AC%E6%84%9F%E6%B8%AC%E5%99%A8%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B/%E4%B8%83%E6%AE%B5%E9%A1%AF%E7%A4%BA%E5%99%A8/Arduino_Seven.JPG?raw=true)

### 七段顯示器分成共陽極和共陰極兩種，不管是哪一種，內部構造都是由 8 個 LED 發光二極體所組成，其中七個是筆劃，另外一個是小數點，如下圖所示，依順時針方向分別為 a, b, c, d, e, f, g 以及小數點 dp (decimal point):
>![](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/%E4%B8%83%E6%AE%B5%E9%A1%AF%E7%A4%BA%E5%99%A8/seven.jpg?raw=true)

### 要產生數字，方法是點亮指定的 LED。例如要產生數字 0，便點亮 a, b, c, d, e, f 等節段；要產生數字 1，便點亮 b, c 等節段；要產生數字 2，便點亮 a, b, d, e, g 等節段，依此類推。以共陰極而言，0 到 9 這十個阿拉伯數字與各節段的對應表如下：
>![](https://github.com/derricktsai0904/Course/blob/main/2024.09%E6%84%9F%E6%B8%AC%E5%85%83%E4%BB%B6/%E4%B8%83%E6%AE%B5%E9%A1%AF%E7%A4%BA%E5%99%A8/seven_tb.jpg?raw=true)

## 相關函式 : 無

## 程式說明

[以下程式來源 Seven.ino ]:https://github.com/derricktsai0904/Arduino/blob/master/02%20Arduino%20%E5%9F%BA%E6%9C%AC%E6%84%9F%E6%B8%AC%E5%99%A8%E5%AF%A6%E4%BD%9C%E7%AF%84%E4%BE%8B/%E4%B8%83%E6%AE%B5%E9%A1%AF%E7%A4%BA%E5%99%A8/Seven.ino "Seven.ino"
[以下程式來源 Seven.ino ]
``` arduino

int i;
int j;

// 設定一個 matrix，B0111111 最前面的 B 代表資料型態為 byte
// 後面跟的 0111111 則是上面對照表的 gfedcba 
const byte num[10]={
    B0111111,  //0
    B0000110,  //1
    B1011011,  //2
    B1001111,  //3
    B1100110,  //4
    B1101101,  //5
    B1111101,  //6
    B0000111,  //7    
    B1111111,  //8
    B1101111   //9    
};

// 設定顯示器各段對應的 pin
const int seg[]={2,3,4,5,6,7,8};  //ABCDEFG

// 設定各段 pin 為 output
void setup() 
{ 
  for(i=0;i<7;i++)
    pinMode(seg[i],OUTPUT);
}
void loop() 
{
  for(i=0;i<10;i++)
  {
    for(j=0;j<7;j++)
    {
  // 讀取 0~9 matrix 裡的數字，ex: B0111111 的第0~6個位元
  // 並由對應的 pin 腳輸出高電壓，使 7 段 LED 發出對應的明亮
      if(bitRead(num[i],j))
        digitalWrite(seg[j],HIGH);
      else
        digitalWrite(seg[j],LOW);        
    }
  delay(1000);    
  } 
}
```
