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
        <b>github.com/ztao1991</b>
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
## 模拟计算（C++）（附页1-2）

## 数据处理（Python）（附页3）

## 原始数据（Txt）（附页4）

# 输出
<!--![pic alt](figure_1-2.png "Sandpile-Model_S")-->
<div style="text-align:center;margin-top:20px">
    <img src="sandpile_model_N.png"/>
    <p>
    <font size="3" face="Helvetica">
        <b>随着沙子的增加T沙堆的高度N</b>
    </font>
    </p>
</div>

------------------------

<div style="text-align:center;margin-top:20px">
    <img src="sandpile_model_S.png"/>
    <p>
    <font size="3" face="Helvetica">
        <b>雪崩的大小S及其概率D(S)</b>
    </font>
    </p>
</div>

---------------------------

<div style="text-align:center;margin-top:20px">
    <img src="sandpile_model_T.png"/>
    <p>
    <font size="3" face="Helvetica">
        <b>雪崩的持续时间T及其概率D(T)</b>
    </font>
    </p>
</div>

# 小结

 <p>
    <font size="3" face="Helvetica">
由以上的实验结果看来当沙子加到某个时刻，沙堆的高度将会保持不变，此时达到了稳定的状态，而随机的加入一个沙子，状态不变，其雪崩的大小S的概率和雪崩持续的时间T的概率满足幂率分布，沙堆的确存在SOC。
    </font>
    </p>

<!--Markdown-->
