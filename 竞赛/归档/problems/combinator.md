


**时间限制：** 1.0 秒 


**空间限制：** 512 MiB

**相关文件：** 题目目录




## 题目描述

回忆组合数 $C_i^j$ 的值

+ 当 $i < j$ 时 $C_i^j=0$
+ 当 $i \ge j$ 时 $C_i^j=\frac{i!}{j!(i-j)!}$

此题目中给定数组$a_1 \ldots a_n$。 你需要计算 $b_1 \ldots b_n$。

其中 $$ b_i = \sum_{j=1}^iC_{i-j+1}^k\times a_i \mod \space 998244353  $$

由于数据量较大，输入和输出的时候会采用相应的加密、解密方法。

## 输入格式

从标准输入读入数据。

输入共一行包含六个整数 $n, a_1, x, y, m, k$

你需要用上述数据生成 $a_1 \ldots a_n$

其中 $a_1$ 已经给出

对于 $i \ge 2$, $a_i = (a_{i-1}x+y) \mod m$

## 输出格式

输出到标准输出。

对于数组 $b$，输出一个哈希值$x$。

设 $c_i = i\times b_i$

$x$是$c_i$的异或和。








## 样例1输入

```plain
5 8 2 3 100 2

```



## 样例1输出

```plain
1283
```


 
	


<table class="table table-bordered"><thead><tr><th rowspan="1">测试点</th><th rowspan="1">$n$</th><th rowspan="1">$m$</th><th rowspan="1">是否为完全二叉树</th></tr></thead><tbody></tbody></table> 

+ 对于30%的数据，$n < 1000$
+ 对于另外20%的数据， $k = 1$
+ 对于另外20%的数据， $x = 1, y = 0$
+ 对于100%的数据， $n \le 10^7, k \le 5, 0 \le a_1, x, y < m, 2 \le m \le 998244353$