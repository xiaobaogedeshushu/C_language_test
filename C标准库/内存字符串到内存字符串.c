#include <stdio.h>

void test_sscanf(void)
{
	int day, year;
	char weekday[20], month[20], dtm[100];

	strcpy(dtm, "Saturday March 25 1989");
	sscanf(dtm, "%s %s %d  %d", weekday, month, &day, &year);


	char a = 'a';
	char str[3];
	int ret = snprintf(str, sizeof(str), "%x", a);
	//int ret = snprintf(str, 2, "%x", a);
	/*	����3�д���˵����
	1��snprintf���Ĳ�������Դ�����������ַ������ַ�;
	2��snprintf�ڶ�������������Ҫ���ϡ���Դ������Ч�ַ���
	��Ҫ�ǵü�����Ϊ�ַ����Զ�����'\0',����Ҫ��1������д�� sizeof(str)�ǱȽϱ��յġ�
	3��snprintf���ڿ�������Ч�ַ���������������'\0'	*/


	char test[8]; 
	int ret2 = snprintf(test, 5, "1234567890");
	printf("%d|%s\n", ret, test);
	/*	���Ϊ��
	ret2Ϊ10
	testΪ1234

	����2�д���˵����
	1��snprintf�Ĳ���������3����ֻҪ��Դ���ַ������ɡ�
	2��ret����Դ�ַ�������,����ʵ�ʿ�����Ҳ������'\0',	
	3��ʵ�ʿ����ĳ��ȵ����ֵ�ǣ�size-1��Դ�ַ������ȵ���Сֵ��
	*/

	char test_2[8];
	int ret3 = snprintf(test_2, 8, "1234567890");//�ڶ�����������Ŀ������ֵ���������ڶ�������С�ڻ����Դ�ĳ��ȣ���Ŀ����ڽ�β�Զ���'\0'
	//int ret3 = sprintf(test_2, "1234567890");//������ôд�������������һ��һ���ã��ᵼ�³�����Ϊ�ַ���Ҫ��'\0'��β��
	//printf("%d|%s\n", ret3, test_2);

}
