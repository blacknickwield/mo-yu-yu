前缀和问题的变形

首先需要一个初始值，然后才能进行前缀和的转移。选第一个位置作为初始值，它的计算与$k$的正负有关。因为是一个循环数组，所以$k$的正负关系到如何进行模运算。
$$
ans[0]=\begin{cases}
\sum_{i=1}^{|k|}code[(i+n)\%n],\quad k\geq 0\\
\sum_{i=1}^{|k|}code[(-i+n)\%n],\quad k<0\\
\end{cases}
$$
得到初始值之后，就可以根据前缀和的方式进行推算。本题中要求的是***当前元素之后的$k$个元素的和***。当$k$>0时，$ans[i]$与$ans[i-1]$相比，少了$code[i]$，多了$code[i]$后面的第$k$个元素；当$k$<0时，多了$code[i]$之前的那个元素，少了$code[i-1]$之前的第$k$个元素。由此我们可以得到对于任意的$ans[i]$，有如下的计算公式
$$
ans[i]=\begin{cases}
ans[(i-1+n)\%n]-code[i]+code[(i+k+n)\%n],\quad k>0\\
ans[(i-1+n)\%n]+code[(i-1+n)\%n]-code[(i-1+k+n)\%n],\quad k<0\\
\end{cases}
$$






