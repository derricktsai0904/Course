
# OpenCV 是什麼？
OpenCV 全名是 Open Source Computer Vision Library ( 開源計算機視覺函式庫 )，OpenCV 由 Intel 發起並開發，以 BSD 授權條款授權發行，可以在商業和研究領域中免費使用，是目前發展最完整的電腦視覺開源資源。

OpenCV 常應用於擴增實境、臉部辨識、手勢辨識、動作辨識、運動跟蹤、物體辨識或圖像分割...等領域，能使用各種不同語言 ( Java、Python、C/C++...等 ) 進行開發，由於 OpenCV 的高執行效率，甚至可用來開發 Real-time 的應用程式。

---

首先安裝 oepncv 套件，如下指令
```
!pip install opencv-python
```

安裝畫面如下<br>
<img src="install_01.jpg" width="400" height="200" />
<br>

如果安裝出現 defaulting to user installation because normal site-packages is not writeable
請到 \anaconda3\Lib\site-packages 將 site-packages 資料夾屬性設為 可允許修改
然後 再重新安裝一次就可以


---
# 讀取圖片練習
請照以下程式碼執行

讀圖方式一
```
from IPython.display import Image, display

display(Image(filename="lenna.jpg"))
```

顯示結果
<hr>
<img src="jupyter-lenna.jpg" width="200" height="200" />
<hr>

讀圖方式二
彈出 Windows 視窗
```
import cv2

image = cv2.imread("lenna.jpg")
cv2.imshow("lenna",image)

cv2.waitKey(0)
cv2.destroyAllWindows()
```
顯示結果



```
import cv2
from matplotlib import pyplot as plt

im = cv2.imread("lenna.jpg",1)  # load image as bgr
im2 = im[:,:,::-1]              # Convert image as rgb
plt.imshow(im2)
plt.show()
```









