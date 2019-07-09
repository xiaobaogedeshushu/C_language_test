#include <stdio.h>

/*
重定向标准输出流，尝试了三种方法：
1、（失败）重写fputc函数；
2、（失败）在VS的编译属性框（Configuration Properties--Debugging--Command Arguments）里添加命令参数：>data.txt
3、（成功）使用C标准库的freopen函数。
4、重写printf函数
*/

#if 0
int fputc(int input, FILE* stream)
{
	FILE* fp;

	fp = fopen("1.txt","a");

	int ret  = fwrite(&input, sizeof(input), 1, fp);

	fclose(fp);

	return ret;
}
#endif


void test_printf(void)
{
	freopen("out.txt", "w", stdout);//会按第二个参数创建并打开第一个参数指向的文件，并把第三个参数的输出流重定向为第一个参数。

	//printf默认输出到标准输出流，它的实现是在内部调用fputc，如果重写fputc可以对printf重定向。
	int a = 10;
	printf("test_printf----%d\n",a);


}