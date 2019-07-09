#include <stdio.h>

/*
函数名：test_perror
结果输出：This is perror--: No such file or directory
*/
void test_perror(void)
{
	FILE *fp;

	/* 首先重命名文件 */
	rename("file.txt", "newfile.txt");

	/* 现在让我们尝试打开相同的文件 */
	fp = fopen("file.txt", "r");
	if (fp == NULL) {
		perror("This is perror--");
		return(-1);
	}
	fclose(fp);
}