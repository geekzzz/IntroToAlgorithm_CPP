�ο���

https://leetcode.windliang.cc/leetCode-33-Search-in-Rotated-Sorted-Array.html


[ 4 5 6 7 1 2 3 ] ��[ 4 5 6 7 ] �� [ 1 2 3 ] ��������

������ [ 1 2 3 4] ���֣����Կ��� [ 1 2 3 4 ] �� [ ] �������������

����������Ҫ�ҵ� target �� target ���ڵ���һ�Σ��������ֿ��Կ��������������������Ϳ��Կ���������ˣ������������Ķ��ַ�ȥ�� target �ˣ�����

[ 4 5 6 7 1 2 3] ����� target = 5����ô������Կ��� [ 4 5 6 7 inf inf inf ]��

[ 4 5 6 7 1 2 3] ����� target = 2����ô������Կ��� [ -inf -inf - inf -inf 1 2 3]��

�ͽⷨһһ��������ÿ��ֻ���� mid ��ֵ������ mid Ҫô���� nums [ mid ]��Ҫô���� inf ���� -inf��

ʲôʱ���� nums [ mid ] �أ�

�� nums [ mid ] �� target ��ͬһ����ߡ�

��ô�ж� nums [ mid ] �� target ��ͬһ�Σ�

�� nums [ mid ] �� target ͬʱ�� nums [ 0 ] �Ƚϣ�������������� nums [ 0 ] ���߶�С�� nums [ 0 ]����ô�ʹ���������ͬһ�Ρ�����

[ 4 5 6 7 1 2 3]����� target = 5����ʱ���鿴�� [ 4 5 6 7 inf inf inf ]��nums [ mid ] = 7��target > nums [ 0 ]��nums [ mid ] > nums [ 0 ]������������ͬһ�� nums [ mid ] = 7�����ñ仯��

��ô�ж� nums [ mid ] �� target ����ͬһ�Σ�

�� nums [ mid ] �� target ͬʱ�� nums [ 0 ] �Ƚϣ��������һ������ nums [ 0 ] һ��С�� nums [ 0 ]����ô�ʹ�����������ͬһ�Ρ�����

[ 4 5 6 7 1 2 3]����� target = 2����ʱ���鿴�� [ - inf - inf - inf - inf 1 2 3]��nums [ mid ] = 7��target < nums [ 0 ]��nums [ mid ] > nums [ 0 ]��һ�����ڣ�һ��С�ڣ��������ǲ���ͬһ�� nums [ mid ] = - inf������˸������