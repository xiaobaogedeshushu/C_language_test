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
	//测试vfprintf
	char array_test_vfprintf[] = "write to fvprintf_output.txt";

	test_vfprintf( "%s", array_test_vfprintf);//直接输出到这个函数里指定的磁盘文件。



	//测试文件操作函数
	test_fileoper();

	//测试printf函数
	test_printf();

	//测试perror函数
	test_perror();

	//测试sscanf函数
	test_sscanf();


	//测试随机数函数
	test_rand();


	//测试时间函数
	test_time();

	//测试排序函数
	test_qsort();




#if 0
	test_goto();
	test_setjmp(6, 2);
	test_memcpy();
#endif
	getchar();
	
	return 0;

}