#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "main.h"



int g_array_backups[MAX] = { 0 };

//�Ƚ�������,��������Ǹ�C��׼��qsort������Ϊ����ָ����õ�
int compar(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;//���ڵ�д�������������Ϊb��ȥa������ʵ�ֽ���
}

//����������
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



	//�����鸳ֵ,��1��10000�Ȳ�����
	for (i = 0; i<MAX; i++)
	{
		array[i] = i+1;
	}

	int start_time = clock();//��ȡ����ʼ����ʱ��
	temp = time(NULL);

	/* ��ʼ������������� */
	//srand((unsigned) time(&t));//һ�㶼�Ὣϵͳʱ����Ϊ���������
	srand((unsigned)time(NULL));

	//����һ������
	for (i = 0; i<5000; i++)
	{ 
		swap(&array[rand() % 10000], &array[rand() % 10000]);
	}

	//����������ҵ�����
	memcpy(g_array_backups, array, sizeof(int)*MAX);

	//�������������
	qsort(array, sizeof(array)/sizeof(int), sizeof(int), compar);
}