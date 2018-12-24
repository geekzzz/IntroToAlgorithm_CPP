先用一个while来排除掉空格，然后解决+ - ，最后计算，注意判断是否超过INT_MAX和INT_MIN():
if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '7' > 0))
				return sign ? INT_MAX : INT_MIN;

参考：https://blog.csdn.net/u010325193/article/details/80287777
C中int类型是32位的，范围是-2147483648到2147483647 
头文件中定义方法为：
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

在C/C++语言中，不能够直接使用-2147483648来代替最小负数，因为这不是一个数字，而是一个表达式。表达式的意思是对整数21473648取负，但是2147483648已经溢出了int的上限，所以定义为（-INT_MAX -1）。
C中int类型是32位的，范围是-2147483648到2147483647 。 
（1）最轻微的上溢是INT_MAX + 1 :结果是 INT_MIN; 
（2）最严重的上溢是INT_MAX + INT_MAX :结果是-2; 
（3）最轻微的下溢是INT_MIN - 1:结果是是INT_MAX; 
（4）最严重的下溢是INT_MIN + INT_MIN:结果是0 。