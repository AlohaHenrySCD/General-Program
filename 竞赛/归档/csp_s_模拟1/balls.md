


**时间限制：** 1.0 秒 


**空间限制：** 512 MiB

**相关文件：** 题目目录




## 题目背景

## 题目描述

你有 $n$ 个盒子排成一排，以及 $m(m < n)$ 个球，每个盒子最多放一个球，也有些盒子是空的。每个时间步你可将一个球从一个盒子移动到盒子旁边的空盒子里面。

求问$k$时间片之后，可以有多少种不同的状态，两个状态不同当且仅当一个状态的某个盒子里有球而另一个没有。由于结果可能很大，你只需要输出答案对 $10^9+7$ 取模的结果即可。

## 输入格式

从标准输入读入数据。

输入第一行两个整数$n, k$ 如题目描述。

输入第二行 $n$ 个 0 或 1构成的序列。表示球的初始状态，如果位置是0表示该盒子没有球，否则表示有球。

## 输出格式

输出到标准输出。

输出一个整数，表示可能的状态数对$10^9+7$ 取模的结果。








## 样例1输入

```plain
4 1
1 0 1 0
```



## 样例1输出

```plain
3
```









## 样例2输入

```plain
10 6
1 0 0 1 0 0 0 1 1 1

```



## 样例2输出

```plain
69
```


## 子任务

+ 对于30%的数据，满足$n \le 30, k \le 10$
+ 对于60%的数据，满足$n \le 1000, k \le 100$
+ 对于100%的数据，满足 $n \le 1500, k \le 1500$ 
+ 数据中均匀存在30%的数据，满足空位数量远大于球数或者球数远大于空位数量。

## 评分方式

## 提示