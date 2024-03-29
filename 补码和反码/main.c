/*
这个工程是研究、验证“原码、反码、补码”的知识。
*/

/*
一、基础名词性概念：
定义：
机器数（第一位表示正负，也叫形式值，形式值就是直接转二进制值）
真值：（数学中的值，有正负。将带符号位的机器数对应的真正数值称为机器数的真值。）
原码：原码就是符号位加上真值的绝对值。（kevin认为就是机器数）
反码：正数的反码是其本身。
	 负数的反码是其原码的基础上，符号位不变，其余各个位取反。（反码本质是一个数对于一个模的同余数，并且这个模为127。补码是将这个模变为128）
补码：正数的补码是其本身。
	 负数的补码是反码加一。

记忆的方法：
	来源，即设计的目的：让计算机把符号位也纳入到计算的范畴里，也就是把减法变成加法。

	生活中的例子：时钟转盘的特性。
	数学原理：利用同余数的两个定理:反身性和线性运算定理，找到一个负数的正数同余数。

	一个数的反码, 实际上是这个数对于一个模的同余数。补码相当于让模增加1。

	即：
	根据
	(-1) mod 127 = 126

	126 mod 127 = 126
	得到
	(-1) ≡ 126 (mod 127)	

	2-1 ≡ 2+126 (mod 127)

	所以126是-1相对于127这个模的同余数。
	
*/

#include <stdio.h>
#include <math.h>

void function1(void);
void function2(void);
double MOD(double x, double y);
int main()
{
	unsigned int zero = 0;
	unsigned int comp_zero = 0xFFFF;//取反，这样写不是严谨的写法，在某些情况下会出错。当int型只有16bit的时候出错。
	unsigned int comp_zero_1 = ~0;	//这是合理、严谨的写法。
	function1();
	function2();
	return 0;
}


/*整数自动转换原则：当表达式中存在有符号类型和无符号类型时，所有的操作都自动转换为无符号类型*/
void function1(void)
{
	unsigned int a = 6;
	int b = -20;
	(a + b > 6) ? puts(">6") : puts("<=6");//结果是>6
	printf("a+b = %d\n", a + b);//结果是显示-14
	printf("a+b = %u\n", a + b);//结果是显示4294967282,也就是把最高一位也认为是绝对值的一部分。
								//十六进制是FFFF FFF2，也就是-14的补码的形式。
}


/*
取模和取余的区别：
如果两个数同号，则取模和取余结果相同；
如果两个数异号，则结果不同；
*/
void function2(void)
{
	//这两句相当于取余，等同于C语言的取余符号:%，也相当于math里的 fmod函数
	int yushu = ceil(3/-5);//向0取整
	yushu = 3 - -5 * yushu;//结果为~1

	//取余运算符，只能操作整型数据
	int rem = 3 % -5;

	//取余运算，可以操作浮点型数据
	int remainder = (int)fmod(3,-5);

	//这两句相当于取模
	int modshu = MOD(3,-5);//向负无穷取整
}

//取模函数
double MOD(double x, double y)
{
	long n;
	double f;
	if ((x<0.000000000000001 && x>-0.000000000000001) || (y<0.000000000000001 && y>-0.000000000000001))return x;//不知道这样写的目的是什么，是为了数据不超过double型的精度？
	f = x / y;
	n = (long)f;//只取整数部分，作用相当于floor函数。
	if (n>f) n = n - 1;//如果只取整数部分还比原来的大，说明是负数，则向负无穷取整。
	f = x - n*y;
	return f;
}