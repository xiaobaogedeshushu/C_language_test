/*
�����ķ����У�
1�������м����
2�������������
3������ָ��
4�������ȼ��ټ����ȳ��ٳ���ע����ܻᵼ�������

Ӧ�ã�������������������Ҫ����ĳ�����
*/
#include <stdio.h>


#define SWAP(a,b)    (a^=b,b^=a,a^=b)		//ע�⣬a��b������ͬһ����������Ȼ�ͻᵼ�½������0.���Ҵӻ��Ľ������������3����䣬�ٶ��ϲ����û�졣


/*
���ƣ�swap
���ã������������Ĵ�С
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
	//		printf("a = %d",a);//��������0

	int temp = c;
	d = c;
	c = temp;
}


