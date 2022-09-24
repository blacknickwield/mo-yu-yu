多维费用背包问题

定义$dp[i][j][k]$为在前$i$个字符串的子集中，$0$和$1$数量上限分别为$j$和$k$的情况下，能取得的最大字符串的数量。由此可以得到如下状态转移方程
$$
dp[i][j][k]=\begin{cases}
dp[i-1][j][k],\quad j<zeros\space or\space k<ones\\
max(dp[i-1][j][k],dp[i-1][j-zeros][k-ones]+1),\quad j\geq zeros\space and\space k\geq ones\\
\end{cases}
$$
对问题的划分：取/不取第$i$个字符串

采用状态压缩可以进一步优化时间复杂度，同样要注意遍历的顺序。因为$dp[i-1][j][k]$代表的是前$i-1$个字符串子集下的子问题，所以为了防止其被更新，需要从后往前遍历。

```cpp
for (int j = m; j >= zeros; --j) {
    for (int k = n; k >= ones; --k) {
        dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones] + 1);
    }
}
```

