#include <stdio.h>
#include <stdarg.h>

/*
测试文件操作的相关函数
（f开头的函数）
*/
void test_fileoper(void)
{
	FILE* fp;
	char s[] = "this is a string";
	char c = '\n';
	fp = fopen("data.txt","w");
	char string[] = "test";
	fwrite(string, sizeof(char), sizeof(string) / sizeof(char), fp);
	fprintf(fp, "%s%c", s, c);
	fclose(fp);

}

/*
目的：测试vfprintf函数
来源：
https://blog.csdn.net/tongsean/article/details/40901827
利用va_list，vfprintf等定义自己的文件输出函数
*/
void test_vfprintf(char* format, ...)//相当于LOG函数
{
	FILE* fp;
	fp = fopen("fvprintf_output.txt", "w");


	va_list args;

	va_start(args, format);
	int temp = vfprintf(fp, format, args);//返回值等于写入成功的字节数
	va_end(args);

	//接下来要不要刷新缓存呢？
	fflush(fp);
}
