#include <stdio.h>
#include "main.h"


int test_setjmp(int a, int b);
void test_goto(void);
void test_memcpy(void);
void test_time(void);
void test_qsort(void);
void test_perror(void);
void test_printf(void);
void test_fileoper(void);
void test_vfprintf(char* format, ...);

//extern int g_array_backups[];



int main()
{
	//����vfprintf
	char array_test_vfprintf[] = "write to fvprintf_output.txt";

	test_vfprintf( "%s", array_test_vfprintf);//ֱ����������������ָ���Ĵ����ļ���



	//�����ļ���������
	test_fileoper();

	//����printf����
	test_printf();

	//����perror����
	test_perror();

	//����sscanf����
	test_sscanf();


	//�������������
	test_rand();


	//����ʱ�亯��
	test_time();

	//����������
	test_qsort();




#if 0
	test_goto();
	test_setjmp(6, 2);
	test_memcpy();
#endif
	getchar();
	
	return 0;

}