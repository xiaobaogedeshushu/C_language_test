#include <stdio.h>

/*
��������test_perror
��������This is perror--: No such file or directory
*/
void test_perror(void)
{
	FILE *fp;

	/* �����������ļ� */
	rename("file.txt", "newfile.txt");

	/* ���������ǳ��Դ���ͬ���ļ� */
	fp = fopen("file.txt", "r");
	if (fp == NULL) {
		perror("This is perror--");
		return(-1);
	}
	fclose(fp);
}