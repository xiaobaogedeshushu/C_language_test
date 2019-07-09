#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "main.h"



int g_array_backups[MAX] = { 0 };

//比较两个数,这个函数是给C标准库qsort函数作为函数指针调用的
int compar(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;//现在的写法是升序，如果改为b减去a，则能实现降序
}

//交换两个数
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void test_rand(void)
{
	int i, n, a, b;
	int array[MAX];
	time_t t;
	long temp;



	//给数组赋值,从1到10000等差数列
	for (i = 0; i<MAX; i++)
	{
		array[i] = i+1;
	}

	int start_time = clock();//获取程序开始运算时间
	temp = time(NULL);

	/* 初始化随机数发生器 */
	//srand((unsigned) time(&t));//一般都会将系统时间作为随机的种子
	srand((unsigned)time(NULL));

	//打乱一个数组
	for (i = 0; i<5000; i++)
	{ 
		swap(&array[rand() % 10000], &array[rand() % 10000]);
	}

	//备份这个打乱的数组
	memcpy(g_array_backups, array, sizeof(int)*MAX);

	//对数组进行排序
	qsort(array, sizeof(array)/sizeof(int), sizeof(int), compar);
}