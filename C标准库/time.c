#include <time.h>
#include <windows.h>


/*
��������test_time
���ã�����clock��time����������
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