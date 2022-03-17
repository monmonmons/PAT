# PAT 

编程语言：c语言

题目网址：https://pintia.cn/problem-sets/994805342720868352/problems/type/7

****
### Advanced level

- **1003**
  - **Dijskra算法**
- **1008**
  - 电梯下降时，层数是**负数**
- **1010**
  - 进制数查找范围：从出现最大数字+1开始，到该数本身
  - 使用**二分法**查找
- **1012**
  - 先排序，再记排名
- **1025**
  - 先分地区排序，记录`local_rank`，最后总排序并输出`final_rank`
  - 用`long long`存register number，注意输出是13位数字，左边补零,`%013lld`
  - 用`long long`存register number，写比较函数时，返回值是`int`，可能溢出
- **1024**
  - 用`long long`存数，有两个测试点通不过
  - 用字符串存数和加法，注意进位`carry`
  

- **1059**
  - 用“筛法”把所有素数标记出来，然后对输入`N`进行素数分解
  - N本身是素数，输出`N=N`
- 

