/*
̷��ǿ���е�����
����:����һ���ַ���ͳ�����ж��ٸ����ʣ�����֮���ÿո�ָ���
��ƣ�������벿�ֱ����Ÿ������жϣ���û���ơ�
*/
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256
#define WORD_START 1
#define NOT_WORD_START 0

int main()
{
	char string[MAX];
	int i, word_num = 0, word_state = NOT_WORD_START;//�����־��������˼�ǣ��������ո������ţ���������ĸ����Ϊ�µ��ʿ�ʼ��
	char c;
	gets(string);
	for (i = 0; (c = string[i]) != '\0'; i++)
	{
		if (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?')word_state = NOT_WORD_START;
		else if (word_state == NOT_WORD_START)
		{
			word_state = WORD_START;
			word_num++;
		}

	}
	printf("There are %d words in this line.\n", word_num);
	system("pause");
	return 0;
}
#endif
#if 0
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	const char str[80] = "This is - www.w3cschool.cc - website";
	const char s[2] = "-";
	char *token;

	/* ��ȡ��һ�����ַ��� */
	token = strtok(str, s);

	/* ������ȡ���������ַ��� */
	while (token != NULL)
	{
		printf(" %s\n", token);

		token = strtok(NULL, s);
	}

	return(0);
}
#endif
#if 0
#include<stdio.h>
int main()
{
	char age = 18;
	char *p1 = &age;
	void *p2 = (void *)p1;
	printf("p1��ַ��ŵĶ����ǣ�%d\n,p1��ֵ�ǣ�%X\n",*p1,p1);
	printf("p2��ַ��ŵĶ����ǣ�%d",*p2);
	return 0;
}


#endif 


#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;


s8 str_hex2str_dec(u8 * des, const u8 * src, size_t n);
void test(void);
void test2(void);
void test3(void);



/*
@brief  str_hex2str_dec
@param  I:	const u8 * src	//������ַ��������ʼ��ַ
			size_t n		//������ַ�����ĳ���
		O:	u8 * des		//������ַ���
@return:	0:�ɹ�
@author Kevin
@date   2018
@version v1.0
@note  �ַ�������ʽ��ʮ������ת�����ַ�����ʽ��ʮ���ƣ�������1��int�����ݴ�4���ֽڵı�ʾ����ת��8���ֽڵı�ʾ������
ע�Ȿ�����ľ����ԣ�
1.�ڶ�������src��һ���ֽ����飬��������ֽ�����ĳ��ȱ���Ϊ������������ֵ���������ֵ����Ϊ4.
2.��һ������desӦ����һ��9���ֽڵ��ֽ����飬���һλ���Զ����\0
*/
static s8 str_hex2str_dec(u8 * des, const u8 * src, size_t n)
{
	int i;
	u32 temp = 0;
#if 0
	for (i = 0; i < n; i++)
	{
		temp = temp + (src[i] << ((3 - i) * 8));
	}
#elif 0
	memcpy(&temp, src, n);//���ڴ��С�˵����ƣ�(x86��С��)�������ִ�н���ﲻ��Ԥ�ڡ���������������С���ֽ����д����OK��	
#elif 1
	temp = (src[3] << 0) | (src[2] << 8) | (src[1] << 16) | (src[0] << 24);//����������ַ������Ǵ���ֽ����д����
#endif
	itoa(temp, des, 10);//itoa������������ʾ������
	return 0;
}


void test(void)
{
	int ch = 3;
//	signed char DMAIRQ = (1 << ch);		//char DMAIRQ = 0x08

//	signed char DMAIRQ = ~(1 << ch);	//char DMAIRQ = 0xf7
//	unsigned char DMAIRQ = ~(1 << ch);  //unsigned char = 0xf7

	char DMAIRQ = (~(1 << (ch)) & 0x1F);//char DMAIRQ = 0x17,DMA �жϱ�־
}

void test2(void)
{
	unsigned char WDCTL = 0x01;
	//WDCTL = (0xA0 | WDCTL & 0x0F);//ֵ��ע����ǣ�&���������ȼ������|���㣬�����������ȼ�������������䡣
	WDCTL = WDCTL & 0x0F;//������4��bit������ǰ4��bit
	WDCTL = 0xA0 | WDCTL;//�������ǰ��Ĳ��裬��ô������������ǰ4��bit
}



void test3(void)
{
#if 0
	//char array[20] = "CMD+SLEEP=0\r\n";
	char array[20]  ;

	unsigned int len =  strlen(array);
	printf("%s", array);
#endif
	int ret = strcmp("\n", "\n");

	printf("sizeof(size_t) = %d\r\n", sizeof(size_t));
}