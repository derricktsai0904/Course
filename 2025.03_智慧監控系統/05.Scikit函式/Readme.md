
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
<img src="01.jpg" width="400" height="200" />

### 由上方output資料表來看，可以知道iris這個資料集合主要是紀錄花的種類、花萼及花瓣的長寬。
```
import sklearn
import seaborn as sns
iris = sns.load_dataset('iris')
sns.set()
sns.pairplot(iris, hue='species', size=3)

```
### 顯示結果
<img src="01.jpg" width="400" height="200" />








