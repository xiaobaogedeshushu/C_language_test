#include <stdio.h>

/*
�ض����׼����������������ַ�����
1����ʧ�ܣ���дfputc������
2����ʧ�ܣ���VS�ı������Կ�Configuration Properties--Debugging--Command Arguments����������������>data.txt
3�����ɹ���ʹ��C��׼���freopen������
4����дprintf����
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
	freopen("out.txt", "w", stdout);//�ᰴ�ڶ��������������򿪵�һ������ָ����ļ������ѵ�����������������ض���Ϊ��һ��������

	//printfĬ���������׼�����������ʵ�������ڲ�����fputc�������дfputc���Զ�printf�ض���
	int a = 10;
	printf("test_printf----%d\n",a);


}