
```
<html>

<Script>
function play(){
   var a = document.forms[0].a.value;

   var b = document.forms[0].b.value; 

   document.forms[0].c.value = parseInt(a) + parseInt(b);;
}
</Script>

<body>

<form>

<table border=1 style="width:50%">

  <tr style="background-color:green;color:yellow"> <td>學號</td> <td>姓名</td> </tr>

  <tr> <td>EL114</td> <td>蔡正雄</td> </tr>

</table>
<br><br>

A <br>
<input type="text" name="a" >
<br>
+
<br>
B
<br>
<input type="text" name="b" >
<br>
<input type="button" value="=" onclick='play()' >
<br>
<input type="text" name="c" >

</form>
</body>

</html>


```
