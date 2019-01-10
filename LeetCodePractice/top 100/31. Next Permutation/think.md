Well, in fact the problem of next permutation has been studied long ago. From the Wikipedia page, in the 14th century, a man named Narayana Pandita gives the following classic and yet quite simple algorithm (with minor modifications in notations to fit the problem statement):

Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is sorted in descending order, just reverse it to ascending order and we are done. For example, the next permutation of [3, 2, 1] is [1, 2, 3].
Find the largest index l greater than k such that nums[k] < nums[l].
Swap nums[k] and nums[l].
Reverse the sub-array from nums[k + 1] to nums[nums.size() - 1].


²Î¿¼£ºhttps://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia