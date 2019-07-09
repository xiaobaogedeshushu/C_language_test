/*
谭浩强书中的例子
需求:输入一行字符，统计其中多少个单词，单词之间用空格分隔开
设计：这里加入部分标点符号隔开的判断，还没完善。
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
	int i, word_num = 0, word_state = NOT_WORD_START;//这个标志变量的意思是：先遇到空格或标点符号，再遇到字母才认为新单词开始。
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

	/* 获取第一个子字符串 */
	token = strtok(str, s);

	/* 继续获取其他的子字符串 */
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
	printf("p1地址存放的东西是：%d\n,p1的值是：%X\n",*p1,p1);
	printf("p2地址存放的东西是：%d",*p2);
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
@param  I:	const u8 * src	//输入的字符数组的起始地址
			size_t n		//输入的字符数组的长度
		O:	u8 * des		//输出的字符串
@return:	0:成功
@author Kevin
@date   2018
@version v1.0
@note  字符数组形式的十六进制转换成字符串形式的十进制，仅限于1个int型数据从4个字节的表示方法转成8个字节的表示方法。
注意本函数的局限性：
1.第二个参数src是一个字节数组，而且这个字节数组的长度必须为第三个参数的值，而且这个值必须为4.
2.第一个参数des应该是一个9个字节的字节数组，最后一位会自动变成\0
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
	memcpy(&temp, src, n);//由于大端小端的限制，(x86是小端)这个语句的执行结果达不到预期。如果输入的数组是小端字节序的写法则OK。	
#elif 1
	temp = (src[3] << 0) | (src[2] << 8) | (src[1] << 16) | (src[0] << 24);//用于输入的字符数组是大端字节序的写法。
#endif
	itoa(temp, des, 10);//itoa第三个参数表示几进制
	return 0;
}


void test(void)
{
	int ch = 3;
//	signed char DMAIRQ = (1 << ch);		//char DMAIRQ = 0x08

//	signed char DMAIRQ = ~(1 << ch);	//char DMAIRQ = 0xf7
//	unsigned char DMAIRQ = ~(1 << ch);  //unsigned char = 0xf7

	char DMAIRQ = (~(1 << (ch)) & 0x1F);//char DMAIRQ = 0x17,DMA 中断标志
}

void test2(void)
{
	unsigned char WDCTL = 0x01;
	//WDCTL = (0xA0 | WDCTL & 0x0F);//值得注意的是，&的运算优先级别高于|运算，所以这条语句等价于下面两条语句。
	WDCTL = WDCTL & 0x0F;//保留后4个bit，清零前4个bit
	WDCTL = 0xA0 | WDCTL;//如果有了前面的步骤，那么本步骤是设置前4个bit
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