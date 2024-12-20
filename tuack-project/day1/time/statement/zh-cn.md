{{ self.title() }}

{{ s('description') }}

小 S 是一名时空旅行者，她喜欢在不同的异世界见证文明的发展史。

一个持续时间为 $|S|$ 的文明的发展史可以被记录为一个长度为 $|S|$ 的 01 串，$0$ 代表这个文明处于和平时期，$1$ 代表处于战争时期。

但是旅行结束后，小 S 发现这个世界发生了正好一次可怕的时间逆流！这打乱小 S 已经做好的文明记录！但是由于在异世界中感受不到时间逆流，小S并不知道它发生在了哪一段时间中。

简单来说，一次时间逆流对文明记录的影响是，将这段时间内的记录翻转。

形式化的，一次作用于时间区间 $[l, r]$ （ $1 \leq l \leq r \leq |S|$ ）的时间逆流会将原记录 $S$ 变成 $T$，同时 $T$ 满足：

$$T_i = \begin{cases}S_i, &i < l \text{ 或 } i > r \\ S_{r - (i - l)}, & l \leq i \leq r\end{cases}$$

这里 $01$ 串的下标从 $1$ 开始。

现在小 S 需要修复这个记录，虽然他不知道具体哪一段时间区间受到了翻转。但是她印象中这个文明的战争更多的发生在晚期。也就是说，字典序最小的修复后的文明记录 $T$ 应该就是正确的。

不过小 S 现在在被她的妹妹拉去玩游戏，所以请你帮帮她找到这个正确的记录。

{{ s('input format') }}

输入只有一行一个字符串，表示被打乱的文明记录 $S$。

{{ s('output format') }}

输出一行一个字符串，表示得到的正确文明记录 $T$ ，其字典序应该是所有可能的文明记录中最小的。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

对 $100\%$ 的数据，$1 \leq |S| \leq 100$。$S$ 只含字符 $0,1$。其中 $|S|$ 表示输入字符串的长度。
