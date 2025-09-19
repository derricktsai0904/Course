# 樹梅派腳位對照表

## 樹梅派腳位<br>
<img src="pin1.jpg" width=800 height=500 />

## 樹梅派腳位對照<br>
<img src="pin2.jpg" width=600 height=800 />

## 安裝 GPIO Zero 函式庫
#### sudo apt-get update
#### sudo apt-get install python3-gpiozero

## GPIO 

#### from gpiozero import LED
#### from time import sleep

from gpiozero import LED
from time import sleep
led = LED(18)
while True:
    led.on()
    sleep(1)
    led.off()
    sleep(1)



