{{ self.title() }}

{{ s('description') }}

小 F 会给出一个长度为 $n$ 的数列 $a$，并进行以下五种询问：

- `1 x`：查询数列中有多少个数**刚好等于** $x$ 。
- `2 x y`：查询数列中有多少个数**大于等于** $x$ 并且**小于等于** $y$ 。
- `3 x y`：查询数列中有多少个数**大于等于** $x$ 并且**小于** $y$ 。
- `4 x y`：查询数列中有多少个数**大于** $x$ 并且**小于等于** $y$ 。
- `5 x y`：查询数列中有多少个数**大于** $x$ 并且**小于** $y$ 。

{{ s('input format') }}

第一行读入两个整数 $n,m$，表示数列的长度为 $n$，一共有 $m$ 次询问。

第二行读入 $n$ 个整数表示数列 $a$。

接下来 $m$ 行，每行输入 `p x` 或 `p x y`，表示一个询问，其中 $p$ 表示询问类型。

{{ s('output format') }}

对于每次询问输出一行一个整数表示询问的答案。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('sample', 3) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

对于 $100 \%$ 的数据：$1\leqslant n,m \leqslant 10^{5},$  $-10^9 \leqslant a_i,x,y\leqslant 10^9$。

{{ s('hints') }}

如果你直接通过了本题，请尝试使用同一个自定义函数完成全部操作。

STL 为我们提供了二分查找的强大利器 lower_bound 函数与 upper_bound 函数，请你自行查阅资料，学习前面两个函数的用法，并尝试使用这两个函数通过本题。