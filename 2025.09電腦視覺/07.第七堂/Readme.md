1️⃣ 什麼是遮罩 (Mask)？

在電腦視覺中，遮罩是一個二值圖 (黑白圖)，用來指示哪些區域是我們想處理的，哪些區域要忽略。
白色 (255)：表示需要保留或處理的區域
黑色 (0)：表示要忽略的區域

應用範例：
只對物體進行顏色處理
對人臉或手部進行辨識
去背景 / 抠圖


====================================================<br>
#### 遮罩基本練習
====================================================<br>
```python
import cv2
import numpy as np
import matplotlib.pyplot as plt

# 讀取影像
img = cv2.imread('lenna.jpg')  # 改成你的影像路徑
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

# 建立與影像相同大小的遮罩 (全部黑色)
mask = np.zeros(img.shape[:2], dtype=np.uint8)

# 在遮罩上畫一個白色矩形 (表示保留區域)
cv2.rectangle(mask, (100, 100), (300, 300), 255, -1)  # -1 代表填滿

# 套用遮罩
masked_img = cv2.bitwise_and(img_rgb, img_rgb, mask=mask)

# 顯示結果
plt.figure(figsize=(12,4))
plt.subplot(1,3,1)
plt.title('原圖')
plt.imshow(img_rgb)
plt.axis('off')

plt.subplot(1,3,2)
plt.title('遮罩')
plt.imshow(mask, cmap='gray')
plt.axis('off')

plt.subplot(1,3,3)
plt.title('套用遮罩後')
plt.imshow(masked_img)
plt.axis('off')

plt.show()

```
<br>
<hr>
===========
執行結果
===========

<img src="show01.jpg" /><br>

<hr><hr>


====================================================<br>
#### 圓形遮罩、多邊形遮罩基本練習
====================================================<br>
```python
import cv2
import numpy as np
import matplotlib.pyplot as plt

# 讀取影像
img = cv2.imread('lenna.jpg')  # 改成你的影像路徑
img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

# ===== 1️⃣ 圓形遮罩 =====
mask_circle = np.zeros(img.shape[:2], dtype=np.uint8)
center = (img.shape[1]//2, img.shape[0]//2)
radius = min(img.shape[0], img.shape[1])//4
cv2.circle(mask_circle, center, radius, 255, -1)
circle_result = cv2.bitwise_and(img_rgb, img_rgb, mask=mask_circle)

# ===== 3️⃣ 多邊形遮罩 =====
mask_poly = np.zeros(img.shape[:2], dtype=np.uint8)
pts = np.array([[100,100], [300,50], [400,200], [150,300]], np.int32)
pts = pts.reshape((-1,1,2))
cv2.fillPoly(mask_poly, [pts], 255)
poly_result = cv2.bitwise_and(img_rgb, img_rgb, mask=mask_poly)

# ===== 顯示結果 =====
plt.figure(figsize=(10,6))

plt.subplot(2,3,1)
plt.title('原圖')
plt.imshow(img_rgb)
plt.axis('off')

plt.subplot(2,3,2)
plt.title('圓形遮罩')
plt.imshow(mask_circle, cmap='gray')
plt.axis('off')

plt.subplot(2,3,3)
plt.title('套用圓形遮罩')
plt.imshow(circle_result)
plt.axis('off')

plt.subplot(2,3,5)
plt.title('多邊形遮罩')
plt.imshow(mask_poly, cmap='gray')
plt.axis('off')

plt.subplot(2,3,6)
plt.title('套用多邊形遮罩')
plt.imshow(poly_result)
plt.axis('off')

plt.tight_layout()
plt.show()
```
<br>
<hr>
===========
執行結果
===========

<img src="show02.jpg" /><br>

<hr><hr>






```

