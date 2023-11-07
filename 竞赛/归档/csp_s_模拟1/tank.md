


**时间限制：** 1.0 秒 


**空间限制：** 1024 MiB

**相关文件：** 题目目录




## 题目描述

给定 $n$ 个长度不一的正整数序列，编号为 $1 \sim n$。初始时候的 $n$ 个序列可以为空。有 $Q$ 次操作，每次操作如下所示:

+ $1$ $x$ $id$ 在 $x$ 号序列末尾插入元素 $id$。保证 $x$ 是一个仍然存在的序列，且 $1 \le x,id \le n+q$。
+ $2$ $x$ 删除 $x$ 号序列末尾的元素，保证 $x$ 是一个仍然存在的序列，$x$ 号序列中包含至少一个元素，且 $1 \le x \le n+q$。
+ $3$ num $x_1$ $x_2$ $\dots$ $x_{num}$ 询问如果将 $x_1,x_2,\cdots,x_{num}$ 号序列顺次拼接，得到的新序列的众数。这里我们规定序列的众数为序列中出现次数严格大于一半的数字，如果不存在满足上述条件的数，则返回 $-1$。数据保证对于任意 $i$, $x_i$ 是一个仍然存在的序列，$x_i$ 号序列中包含至少一个元素, 且 $1 \le x_i \le n+q$。注意我们不保证 $x_1,\cdots,x_{num}$ 互不相同。
+ $4$ $x_1$ $x_2$ $x_3$ 新建一个编号为 $x_3$ 序列，其为 $x_1$ 号序列后顺次添加 $x_2$ 号序列元素得到的结果。新建序列后删除 $x_1,x_2$ 序列，$x_1,x_2$ 号对应的序列之后会被视为不存在。保证 $1 \le x_1,x_2,x_3 \le n+Q, x_1 \neq x_2$, $x_1,x_2$ 在操作前是一个仍然存在的序列，且在操作前没有序列曾经使用过编号 $x_3$。

## 输入格式

从标准输入读入数据。

输入的第一行包含两个正整数 $n$ 和 $q$，保证 $n \le 5 \times 10^{5}$，$q \le 5 \times 10^{5}$，分别表示数列的个数和操作的次数。

接下来 $n$ 行，第 $i$ 行表示编号为 $i$ 的数列。每一行的第一个非负整数 $l_i$ 表示初始第 $i$ 号序列元素个数，这一行接下来有 $l_i$ 个非负整数 $a_{i,j}$ 按顺序表示数列的元素。假定 $C_l = \sum{l_i}$ 代表输入序列长度之和，则保证 $C_l \le 5 \times 10^{5}$，$a_{i,j} \le n + q$。

接下来 $q$ 行，每行若干个正整数，表示一个操作，并按照题面描述中的格式输入。假定 $C_{num} = \sum{num}$ 代表所有操作 $3$ 需要拼接的序列个数之和，则保证 $C_{num} \le 5 \times 10^{5}$。

## 输出格式

输出到标准输出。

对于每次操作三，一行输出一个整数表示对应的答案，








## 样例1输入

```plain
2 8
3 1 1 2
3 3 3 3
3 1 1
3 1 2
4 2 1 3
3 1 3
2 3
3 1 3
1 3 1
3 1 3

```



## 样例1输出

```plain
1
3
-1
3
-1

```









## 样例2输入

```plain
4 9
1 1
1 2
1 3
1 4
3 4 1 2 3 4
1 1 2
3 2 1 2
2 3
3 3 1 2 3
1 4 4
1 4 4
1 4 4
3 4 1 2 3 4
```



## 样例2输出

```plain
-1
2
2
4

```




## 样例3

见题目目录下的 *3.in* 与 *3.ans*。

该样例满足测试点 $1 \sim 3$ 的限制。



## 样例4

见题目目录下的 *4.in* 与 *4.ans*。

该样例满足测试点 $11 \sim 12$ 的限制。

## 数据范围

 
	


<table class="table table-bordered"><thead><tr><th rowspan="1">$n,Q$</th><th rowspan="1">$C_{num},C_{l}$</th><th rowspan="1">测试点编号</th><th rowspan="1">特殊性质A</th><th rowspan="1">特殊性质B</th><th rowspan="1">特殊性质C</th></tr></thead><tbody><tr><td rowspan="1">$\le 300$</td><td rowspan="1">$\le 300$</td><td rowspan="1">1,2,3</td><td rowspan="2">否</td><td rowspan="2">否</td><td rowspan="3">是</td></tr><tr><td rowspan="1">$\le 4,000$</td><td rowspan="1">$\le 4,000$</td><td rowspan="1">4,5,6,7</td></tr><tr><td rowspan="5">$\le 10^{5}$</td><td rowspan="5">$\le 10^{5}$</td><td rowspan="1">8</td><td rowspan="2">是</td><td rowspan="1">是</td></tr><tr><td rowspan="1">9</td><td rowspan="1">否</td><td rowspan="2">否</td></tr><tr><td rowspan="1">10</td><td rowspan="3">否</td><td rowspan="1">是</td></tr><tr><td rowspan="1">11,12</td><td rowspan="2">否</td><td rowspan="1">是</td></tr><tr><td rowspan="1">13</td><td rowspan="1">否</td></tr><tr><td rowspan="5">$\le 5 \times 10^{5}$</td><td rowspan="5">$\le 5 \times 10^{5}$</td><td rowspan="1">14</td><td rowspan="2">是</td><td rowspan="1">是</td><td rowspan="1">是</td></tr><tr><td rowspan="1">15</td><td rowspan="1">否</td><td rowspan="2">否</td></tr><tr><td rowspan="1">16</td><td rowspan="3">否</td><td rowspan="1">是</td></tr><tr><td rowspan="1">17,18</td><td rowspan="2">否</td><td rowspan="1">是</td></tr><tr><td rowspan="1">19,20</td><td rowspan="1">否</td></tr></tbody></table> 

## 提示