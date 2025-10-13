
<img src="7.gif" /> <br>

## 七段顯示器
七段顯示器（英語：seven-segment display）為常用顯示數字的電子元件。因為藉由七個發光二極體以不同組合來顯示數字，
所以稱為「七劃管」、「七段數碼管」、「七段顯示器」，由於所有燈管全亮時所表示的是「8」，所以又稱「8字管」、「8字顯示器」。
<img src="00.jpg" width=600 height=500 /> <br><br>

## 我們課程上是使用共陰的七段顯示器，參考腳位如下圖
<img src="00-1.jpg" width=600 height=500 /> <br><br>

<hr>

樹梅派正確的接法如下圖所示，每個腳位要串接一個限流電阻，電阻越小顯示器的亮度越大。<br>
<img src="02.jpg" width=600 height=400 /> <br>

樹梅派連結共陰七段顯示器腳位簡圖。<br>
<img src="03.jpg" width=500 height=400 /> <br><br><br><br>

<hr>

## 此次課程的接法如下，省略電阻，直接接到七段顯示器的腳位。

<hr>
<img src="01.jpg" width=1000 height=800 /> <br>

<br>
<br>

<hr>
練習一 : 接好以上電路之後，請執行以下程式範例，是否會出現 『數字 3』。
``` python
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
for x in range(len(pin)):
     GPIO.setup(pin[x], GPIO.OUT)

GPIO.output( 8,False) #a
GPIO.output(10,False) #b
GPIO.output(12,False) #c
GPIO.output(16,False) #d
GPIO.output(18,True) #e
GPIO.output(22,True) #f
GPIO.output(24,False) #g
```





