/*
交换的方法有：
1、利用中间变量
2、利用异或运算
3、利用指针
4、利用先加再减或先乘再除（注意可能会导致溢出）

应用：可以用在有序数列需要逆序的场景。
*/
#include <stdio.h>


#define SWAP(a,b)    (a^=b,b^=a,a^=b)		//注意，a和b不能是同一个变量，不然就会导致结果都是0.而且从汇编的结果看，还多了3条语句，速度上不见得会快。


/*
名称：swap
作用：交换两个数的大小
*/
void swap(int* a,int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void test_swap()
{
	int a = 1;
	int b = 2;

	int c = 3, d = 4;


	//	printf("a = %d, b = %d", a, b);
	SWAP(a, b);
	//		printf("a = %d, b = %d", a, b);
	//	SWAP(a, a);
	//		printf("a = %d",a);//结果变成了0

	int temp = c;
	d = c;
	c = temp;
}


