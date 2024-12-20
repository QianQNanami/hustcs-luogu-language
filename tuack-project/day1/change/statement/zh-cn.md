{{ self.title() }}

{{ s('description') }}

对于平面直角坐标系上的点 $(x,y)$ ,我们现在有两种坐标变换的方法，方法一是拉伸 $k$ 倍，把坐标变换成 $(kx,ky)$，方法二是通过旋转 $\theta$，把坐标变换为 $(x\cos\theta-y\sin\theta,x\sin\theta+y\cos\theta)$。其中，$\theta$ 的单位为 $\operatorname{rad}$。

现在有一个包含了 $n$ 个坐标变换的序列 $(t_1,t_2,t_3,...,t_n)$ ，其中 $t_i$ 表示了一个坐标变换,然后现在又定义了一个询问，给定 $(i,j,x,y)$ 四元组，询问 坐标 $(x,y)$ 经过 $(t_i,t_{i+1},...,t_j)$ 坐标变换后的坐标,共有 $m$ 个这样的询问,计算出每个询问的结果。

{{ s('input format') }}

输入共 $n+m+1$ 行。

输入的第一行包含空格分隔的两个正整数 $n$ 和 $m$，分别表示坐标变换和询问个数。

接下来 $n$ 行依次输入 $n$ 个坐标变换，第一个数表示采用的方法($1$ 表示拉伸，$2$ 表示旋转)，第二个实数表示 $k$ 或 $\theta$

接下来 $m$ 行依次输入 $m$ 个询问，每行包含空格分隔的四个整数 $i,j,x,y$。

{{ s('output format') }}

输出共 $m$ 行，每行两个实数，表示经过位移变化后的坐标,需要保证绝对误差不大于 $0.1$。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

对于 $100\%$ 的测试数据，$0 \le n,m \le 100000$，$x,y$ 均为整数且绝对值不超过 $1000000$，单个拉伸操作系数 $0.5 \le k \le 2$，任意区间的拉伸系数 $k$ 的乘积满足 $0.001 \le k \le 1000$。

{{ s('提示') }}

前缀和、前缀积及其思想是处理区间可加性问题的利器，请自行查阅资料学习。

在本题中，容易发现拉伸和旋转两种操作顺序无关，可对拉伸和旋转分别应用前缀积、前缀和处理。