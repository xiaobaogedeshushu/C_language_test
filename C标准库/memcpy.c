#include <string.h>


/*
��������test_memcpy

��Ϊmemcpy�����һ����������Ҫ�������ֽڵ���Ŀ��
һ��int����ռ��4���ֽڣ������Ļ���
����5�ֽڣ�ʵ����ֻ���ƶ�2�����֣������ȥ����
���Ҫ��ﵽ��a��ַ��ʼ��5��Ԫ�ؿ�����a+3��ַ������Ҫ��ôд��

memcpy(a + 3, a, 5*sizeof(int));

*/
void test_memcpy(void)
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	memcpy(a + 3, a, 5);
	for (int i = 0; i<10; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}