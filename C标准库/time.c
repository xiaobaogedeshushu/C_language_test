#include <time.h>
#include <windows.h>


/*
函数名：test_time
作用：测试clock和time这两个函数
*/
void test_time(void)
{
#if 1
	int i = 1;
	time_t t;
	int num = 0;


	printf("i =%d clock = %d,time = %ld\n",i,clock(),time(&t) );	

	Sleep(1000);

	printf("i =%d clock = %d,time = %ld\n", i+1, clock(), time(&t));

#endif

}