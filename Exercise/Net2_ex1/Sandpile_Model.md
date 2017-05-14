<!--MathJax-->
<script type="text/javascript"
src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
</script>

<!--Head-->
<head>
  <title></title>
</head>

<!--Title-->
<div style="text-align:center;margin-top:27px;margin-bottom:0px">
    <p>
    <font size="7" face="Helvetica">
        <b>Sandpile-Model</b>
    </font>
    </p>
</div>

<!--Version-->
<div style="text-align:center;margin-top:20px;margin-bottom:70px">
    <font size="2" face="Couriew New">
        <p style="line-height: 0.4em;">
        <b>zhangtao</b>
        </p>
        <p style="line-height: 0.4em;">
        <b>ztao1991@gmail.com</b>
        </p>
        <p style="line-height: 0.4em;">
        <b>2017/04/04</b>
        </p>
    </font>
</div>

<!--Markdown-->

# 沙堆模型
# 实验步骤
# 实验规模
\\( L^2 = 10 \cdot 10;N = 1000000 \\)

# 源代码
## 模拟计算（C++）
[模拟并记录沙堆的高度](https://github.com/ztao1991/Networks/blob/master/Exercise/Net2_ex1/sandpile-model-N.cpp)

[模拟并记录雪崩的规模和时间](https://github.com/ztao1991/Networks/blob/master/Exercise/Net2_ex1/sandpile-model.cpp)

## 原始数据（Txt）
[沙粒的高度](https://github.com/ztao1991/Networks/blob/master/Exercise/Net2_ex1/sandpile-model_N.txt)

[雪崩的规模](https://github.com/ztao1991/Networks/blob/master/Exercise/Net2_ex1/sandpile-model_S.txt)

[雪崩的时间](https://github.com/ztao1991/Networks/blob/master/Exercise/Net2_ex1/sandpile-model_T.txt)


## 数据处理（Python）
[plot_sandpile_model_N.py](https://github.com/ztao1991/Networks/blob/master/Exercise/Net2_ex1/plot_sandpile_model_N.py)

[plot_sandpile_model_TS.py](https://github.com/ztao1991/Networks/blob/master/Exercise/Net2_ex1/plot_sandpile_model_TS.py)

# 输出
<!--![pic alt](figure_1-2.png "Sandpile-Model_S")-->
<div style="text-align:center;margin-top:20px">
    <img src="sandpile_model_N.png"/>
    <p>
    <font size="4" face="Helvetica">
        <b></b>
    </font>
    </p>
</div>


<div style="text-align:center;margin-top:20px">
    <img src="sandpile_model_S.png"/>
    <p>
    <font size="4" face="Helvetica">
        <b></b>
    </font>
    </p>
</div>

<div style="text-align:center;margin-top:20px">
    <img src="sandpile_model_T.png"/>
    <p>
    <font size="4" face="Helvetica">
        <b></b>
    </font>
    </p>
</div>

# 小结

<!--Markdown-->
