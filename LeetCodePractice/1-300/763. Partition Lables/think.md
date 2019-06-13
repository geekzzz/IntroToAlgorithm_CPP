二叉树内的最长路径分两种情况，第一种是经过root，那么最长路径就是左子树的最大深度+右子树的最大深度。第二种情况是不经过root，但是总有一个节点的左子树最大深度加右子树最大深度最大，所以设置一个全局的变量，每次遍历的时候比较一下就行了。

参考：https://leetcode.com/problems/diameter-of-binary-tree/discuss/101132/Java-Solution-MaxDepth