Python 語法 使用 DataFrame 來顯示資料表格

DataFrame 特點
二維結構： DataFrame 是一個二維表格，可以被看作是一個 Excel 試算表或 SQL 表，具有行和列。可以將其視為多個 Series 物件組成的字典。

---

練習 (使用字典來建立df)
```python
import pandas as pd
 
grades = {
    "name": ["Mike", "Sherry", "Cindy", "John"],
    "math": [80, 75, 93, 86],
    "chinese": [63, 90, 85, 70]
}
 
df = pd.DataFrame(grades)
 
print("使用字典來建立df：")
print(df)
```

執行結果
```
使用字典來建立df：
     name  math  chinese
0    Mike    80       63
1  Sherry    75       90
2   Cindy    93       85
3    John    86       70
```

---

練習 (置換 df 的表頭)
```python
import pandas as pd
 
grades = {
    "name": ["Mike", "Sherry", "Cindy", "John"],
    "math": [80, 75, 93, 86],
    "chinese": [63, 90, 85, 70]
}
 
df = pd.DataFrame(grades)
df.columns = ["人員", "數學", "國文"]

print("使用字典來建立df：")
print(df)
```

執行結果
```
使用字典來建立df：
       人員  數學  國文
0    Mike  80  63
1  Sherry  75  90
2   Cindy  93  85
3    John  86  70
```

---

練習 (刪除 df 的某一欄資料)
```python
import pandas as pd
 
grades = {
    "name": ["Mike", "Sherry", "Cindy", "John"],
    "math": [80, 75, 93, 86],
    "chinese": [63, 90, 85, 70]
}
 
df = pd.DataFrame(grades)
del df['math']
 
print("使用字典來建立df：")
print(df)
```

執行結果
```
     name  chinese
0    Mike       63
1  Sherry       90
2   Cindy       85
3    John       70
```

---

安裝股票相關套件 <br>
```
pip install -U quandl numpy pandas matplotlib pystan pytrends plotly yfinance
```

其中 yfinance 安裝會失敗，請一下面指令執行一次
```
python3 -m pip install yfinance
```






