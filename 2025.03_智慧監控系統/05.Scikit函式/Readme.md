
# SKlearn
SKlearn在python中提供大量常見的機器學習演算法和許多實用的資料集合，像是Iris以及手寫辨識數字的資料(之後的程式舉例會用到)。
而演算法的部分，可以在SKlearn官網中看到，他將功能分為6個部分：Classification、Regression、Clustering、Model selection、
Preprocessing、Dimensionality reduction，各個適合的演算法，在SKlearn中也有做相當清楚的圖表，呈現該演算法資料輸出的型態，相當方便。

# 安裝說明
```
pip install -U scikit-learn
```

# 執行步驟

### 在python中可以用seaborn來下載iris數據集合，這個數據集合主要紀錄三種鳶尾的型態。
```
import sklearn
import seaborn as sns
iris = sns.load_dataset('iris')
iris.head()
```
### 顯示結果
<img src="01.jpg" width="400" height="200" /><br>

### 由上方output資料表來看，可以知道iris這個資料集合主要是紀錄花的種類、花萼及花瓣的長寬。
```
import sklearn
import seaborn as sns
iris = sns.load_dataset('iris')
sns.set()
sns.pairplot(iris, hue='species', height=3)
```
### 顯示結果
<img src="02.jpg" width="800" height="800" /><br>

### 將 iris 數據以 KMeans 分為三類
可以分出了三大群出來。此外根據此結果，可以明確解釋：「當花瓣的長度介於1~2公分，且寬度小於1公分時，
可以獨自被分類為一品種。若花瓣長度介於3~5公分左右，且寬度介於1~2公分左右，也可以被定義為一品種。
最後當花瓣長度介於約5~7公分內，且寬度介於約1.5~2.5之間，則可另外被定義成一品種。」。

```
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris

RawData = load_iris()
df = pd.DataFrame(RawData['data'],columns= RawData['feature_names'])

from sklearn.cluster import KMeans
x = df.iloc[:,0:4] #x為所有特徵資料
model = KMeans(n_clusters=3, n_init='auto',random_state=1) #預計分為三群，迭代次數由模型自行定義
model.fit(x) #建立模型
plt.scatter(df['petal length (cm)'],df['petal width (cm)'], c=model.labels_) #根據花瓣的長度、寬度，來畫出之間關係。c=model.labels_:代表資料點的顏色，由模型分類出來的結果，來進行分類和定義。 
plt.xlabel('petal length')
plt.ylabel('petal width')
plt.show()
```







