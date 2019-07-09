#include <string.h>


/*
函数名：test_memcpy

因为memcpy的最后一个参数是需要拷贝的字节的数目！
一个int类型占据4个字节！这样的话，
本题5字节，实际上只能移动2个数字（往大的去）。
如果要想达到将a地址开始的5个元素拷贝到a+3地址处，需要这么写：

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