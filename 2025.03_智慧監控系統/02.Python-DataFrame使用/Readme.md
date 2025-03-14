Python 語法 使用 DataFrame 來顯示資料表格

DataFrame 特點
二維結構： DataFrame 是一個二維表格，可以被看作是一個 Excel 試算表或 SQL 表，具有行和列。可以將其視為多個 Series 物件組成的字典。

練習 (使用字典來建立df)
``` Python
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








