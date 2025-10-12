
### 「影像形態學」是影像處理中的重要技術，主要用於分析與處理二值化影像的形狀結構，藉由對影像中的物件進行「膨脹」、「侵蝕」、「開運算」與「閉運算」等操作，達到去除雜訊、填補空洞、強化結構與物件分割的目的。
這些操作以「結構元素（structuring element）」為基礎，模擬對影像區域的幾何處理，廣泛應用於工業檢測、生物醫學影像、OCR 前處理、智慧交通等領域。

<hr>

## 下圖為先侵蝕，後膨脹的例子 <br>

<img src="01.jpg" /><br>

<hr>

## 下圖為原圖、侵蝕、膨脹、開運算、閉運算的例子 <br>

<img src="02.jpg" /><br>

<hr>

<img src="03.jpg" /><br>

<hr><hr>

### ◎ 膨脹的用法
概念
膨脹是將影像中「白色物件（前景）」往外擴張的形態學運算。

直覺理解：<br>
👉 把影像中的白色區塊「長大」，邊界會向外延伸。<br>
👉 小洞、細縫會被填補，孤立的小區塊可能會連接起來。<br>

#### 範例說明
假設我們有一張簡單的二值化影像（0=黑色，1=白色）

```
原始影像：
0 0 0 0 0
0 0 1 0 0
0 1 1 1 0
0 0 1 0 0
0 0 0 0 0
```

#### 選擇一個 3×3 的十字形結構元素：
```
結構元素：
0 1 0
1 1 1
0 1 0
```

#### 經過膨脹運算後：
```
膨脹後影像：
0 0 1 0 0
0 1 1 1 0
1 1 1 1 1
0 1 1 1 0
0 0 1 0 0
```

#### 以下為實圖的例子：<br>
左：原始影像（有細縫或雜訊） ，  右：膨脹後影像（白色區塊變大、連接起來）
<img src="04.jpg" /><br>

#### 應用情境<br>

🔹 車牌辨識：填補字母或數字中的細縫，方便辨識 <br>
🔹 OCR前處理：連接破碎的字元筆劃 <br>
🔹 影像遮罩處理：擴張標記區域方便後續分析 <br>
🔹 去除小洞或縫隙：強化目標區塊結構 <br>

👉 總結：<br>
「膨脹」是一種讓白色物件變大的運算，適合用來連接斷裂區域、填補空洞，是影像形態學中最基本也最常用的技術之一。


```
import cv2
import numpy as np
import matplotlib.pyplot as plt

# === 1. 讀取影像 ===
# 將 'your_image.jpg' 改成你要處理的圖檔名稱
img = cv2.imread('lenna.jpg')

# === 2. 轉為灰階影像 ===
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# === 3. 二值化處理 ===
# 這會將影像轉為黑白，方便做膨脹
_, binary = cv2.threshold(gray, 127, 255, cv2.THRESH_BINARY)

# === 4. 建立結構元素 (Kernel) ===
kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (7, 7))

# === 5. 執行膨脹運算 ===
dilated = cv2.dilate(binary, kernel, iterations=1)

# === 6. 顯示結果 ===
# OpenCV 使用 BGR，Matplotlib 使用 RGB，因此要轉換
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

plt.figure(figsize=(15,5))

plt.subplot(1,3,1)
plt.title('Original')
plt.imshow(img_rgb)
plt.axis('off')

plt.subplot(1,3,2)
plt.title('Binary')
plt.imshow(binary, cmap='gray')
plt.axis('off')

plt.subplot(1,3,3)
plt.title('Dilated')
plt.imshow(dilated, cmap='gray')
plt.axis('off')

plt.tight_layout()
plt.show()
```
<br><br>
<hr>
===========
執行結果
===========

<img src="05.jpg" /><br>

<hr><hr>





