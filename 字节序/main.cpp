/*来源：深入理解计算机系统*/

#ifdef ZIJIEXU
#include <stdio.h>

#if 0
typedef unsigned int	*byte_pointer;

void show_bytes(byte_pointer arug, int length)
{
	int i;
	for(i = 0; i<length; i++)
	{
		printf("%.2x\n", arug[i]);
	}
}


int main()
{
	int i_temp1 = 1;
	show_bytes((byte_pointer)&i_temp1,sizeof(int));
	//show_bytes();
	//show_bytes();
	return 0;
}
#endif

/*作用：测试指针类型的长度什么时候会是8个字节*/
int main()
{
	int *point = NULL;
	printf("sizeof point = %d", sizeof(point));
	return 0;
}
#endif

#include <stdio.h>

int main()
{
#if 0 

	unsigned short int head = 0;
	head -= 1;
	head += 1;
#endif


	char test[8] = { 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08 };
	int *test_p = (int *)test;
	int a = test_p[0];
	return 0;
}