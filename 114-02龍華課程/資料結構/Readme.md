

以下參考 將 虛擬碼 轉入 chatgpt 產生程式碼，

請參考以下虛擬碼產生網頁程式碼 "Begin 輸入 A,B,C If A > B 則 A -> Max 否則 N-> Max If C > Max 則 C -> Max Print Max End"

<br><br>
<hr>
網頁程式碼
<hr>
``` 網頁程式碼
<!DOCTYPE html>
<html lang="zh-TW">
<head>
<meta charset="UTF-8">
<title>找出三個數字最大值</title>

<style>
body{
    font-family: Arial;
    text-align:center;
    margin-top:50px;
}
input{
    width:80px;
    padding:5px;
    margin:5px;
}
button{
    padding:8px 15px;
    font-size:16px;
}
#result{
    margin-top:20px;
    font-size:20px;
    color:blue;
}
</style>

<script>
function findMax(){

    let A = Number(document.getElementById("A").value);
    let B = Number(document.getElementById("B").value);
    let C = Number(document.getElementById("C").value);

    let Max;

    // If A > B 則 A -> Max 否則 B -> Max
    if(A > B){
        Max = A;
    }else{
        Max = B;
    }

    // If C > Max 則 C -> Max
    if(C > Max){
        Max = C;
    }

    document.getElementById("result").innerHTML = "最大值 Max = " + Max;
}
</script>
</head>

<body>

<h2>三個數字最大值計算</h2>

A：<input type="number" id="A"><br>
B：<input type="number" id="B"><br>
C：<input type="number" id="C"><br><br>

<button onclick="findMax()">計算最大值</button>

<div id="result"></div>

</body>
</html>
```
<br>
<hr>
Python 程式碼
<hr>
```Python
# 輸入 A, B, C
A = float(input("請輸入 A: "))
B = float(input("請輸入 B: "))
C = float(input("請輸入 C: "))

# If A > B 則 A -> Max 否則 B -> Max
if A > B:
    Max = A
else:
    Max = B

# If C > Max 則 C -> Max
if C > Max:
    Max = C

# Print Max
print("最大值 Max =", Max)
```
