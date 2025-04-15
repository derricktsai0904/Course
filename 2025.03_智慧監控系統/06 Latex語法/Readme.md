
Latex 是一種論文的撰寫格式，有自己的一套語法，本課程使用 Overleaf 作為 Latex 語法撰寫的工具。



<details>
<Summary>
  版面排版
</Summary>

```
\documentclass[a4paper,12pt,twoside]{book}
\usepackage{xeCJK}
\begin{document}
\begin{titlepage}
\begin{center}        % 版面置中
\vspace{0.5cm}        % 文字間距 
\LARGE               
Department Name\\       % // -> 跳行
University Name\\
Master Thesis/Doctoral Dissertation\\
\vspace{1.5cm}
\textbf{ Thesis Title}   % 文字加粗
\vspace{1.5cm}
\textbf{ Author Name}
\vfill
\textbf{ Adivisor: Prof. Name}
\vspace{0.8cm}
Date
\end{center}
\end{titlepage}
\end{document}
```

## 顯示結果
<img src="01.jpg" width=400 height=400 />

</details>

<details>
<Summary>
表格說明  
</Summary>

```
\begin{tabular}[t]{|l|l|l|}
\hline
column1 & column2 & column3 \\
\hline
   item1 & item2 & item3 \\
   itemA & itemB & itemC \\
\hline
\end{tabular} 
```
## 顯示結果
<img src="02.jpg" width=400 height=200 />

## 程式說明
\begin{tabular}[t]{|l|l|l|} ：首先 [t] 代表top，也可以是 [b]，button [c]，center。

<hr>

```
\begin{tabular}[t]{|l|l|l|}
\hline
column1 & column2 & column3 \\
\hline
   item1 & item2 & item3 \\
   itemA & itemB & itemC \\
\hline
\end{tabular} 
```
## 顯示結果
<img src="03.jpg" width=400 height=200 />

## 程式說明
\begin{tabular}[t]{|l|l|l|} ：首先 [t] 代表top，也可以是 [b]，button [c]，center。

</details>








