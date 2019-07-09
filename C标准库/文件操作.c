#include <stdio.h>
#include <stdarg.h>

/*
�����ļ���������غ���
��f��ͷ�ĺ�����
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
Ŀ�ģ�����vfprintf����
��Դ��
https://blog.csdn.net/tongsean/article/details/40901827
����va_list��vfprintf�ȶ����Լ����ļ��������
*/
void test_vfprintf(char* format, ...)//�൱��LOG����
{
	FILE* fp;
	fp = fopen("fvprintf_output.txt", "w");


	va_list args;

	va_start(args, format);
	int temp = vfprintf(fp, format, args);//����ֵ����д��ɹ����ֽ���
	va_end(args);

	//������Ҫ��Ҫˢ�»����أ�
	fflush(fp);
}
