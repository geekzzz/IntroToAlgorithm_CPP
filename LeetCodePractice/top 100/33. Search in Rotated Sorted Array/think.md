参考：

https://leetcode.windliang.cc/leetCode-33-Search-in-Rotated-Sorted-Array.html


[ 4 5 6 7 1 2 3 ] ，[ 4 5 6 7 ] 和 [ 1 2 3 ] 两段有序。

而对于 [ 1 2 3 4] 这种，可以看做 [ 1 2 3 4 ] 和 [ ] 特殊的两段有序。

而对于我们要找的 target ， target 不在的那一段，所有数字可以看做无穷大，这样整个数组就可以看做有序的了，可以用正常的二分法去找 target 了，例如

[ 4 5 6 7 1 2 3] ，如果 target = 5，那么数组可以看做 [ 4 5 6 7 inf inf inf ]。

[ 4 5 6 7 1 2 3] ，如果 target = 2，那么数组可以看做 [ -inf -inf - inf -inf 1 2 3]。

和解法一一样，我们每次只关心 mid 的值，所以 mid 要么就是 nums [ mid ]，要么就是 inf 或者 -inf。

什么时候是 nums [ mid ] 呢？

当 nums [ mid ] 和 target 在同一段里边。

怎么判断 nums [ mid ] 和 target 在同一段？

把 nums [ mid ] 和 target 同时与 nums [ 0 ] 比较，如果它俩都大于 nums [ 0 ] 或者都小于 nums [ 0 ]，那么就代表它俩在同一段。例如

[ 4 5 6 7 1 2 3]，如果 target = 5，此时数组看做 [ 4 5 6 7 inf inf inf ]。nums [ mid ] = 7，target > nums [ 0 ]，nums [ mid ] > nums [ 0 ]，所以它们在同一段 nums [ mid ] = 7，不用变化。

怎么判断 nums [ mid ] 和 target 不在同一段？

把 nums [ mid ] 和 target 同时与 nums [ 0 ] 比较，如果它俩一个大于 nums [ 0 ] 一个小于 nums [ 0 ]，那么就代表它俩不在同一段。例如

[ 4 5 6 7 1 2 3]，如果 target = 2，此时数组看做 [ - inf - inf - inf - inf 1 2 3]。nums [ mid ] = 7，target < nums [ 0 ]，nums [ mid ] > nums [ 0 ]，一个大于，一个小于，所以它们不在同一段 nums [ mid ] = - inf，变成了负无穷大。