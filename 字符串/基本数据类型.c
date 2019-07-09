
/*
test_unsigned
当表达式中存在有符号类型和无符号类型时所有的操作数都自动转换为无符号类型。
因此-20变成了一个非常大的正整数，所以该表达式计算出的结果大于6。
这一点对于频繁用到无符号数据类型的嵌入式系统（硬件寄存器的值全部是无符号的）来说是丰常重要的。
*/
void test_unsigned(void)
{
	unsigned int a = 6;

	int b = -20;

	(a + b > 6) ? puts("> 6") : puts("<= 6");//结果是大于6
}




//只取后N个Bit的操作是如何写？



//这里其实是容易混淆sizeof()和strlen()的区别，strlen()是求字符串的长度
//如果a[i] = 0,则打印对应的数组下标。
int test_char()
{
	char a[1000];
	int i;
	for (i = 0; i<1000; i++)
	{
		a[i] = -1 - i;			
	}
	printf("%d", strlen(a));	
	return 0;
}


union info_u
{
	unsigned char version;
	unsigned char version1;
	unsigned char version2;
	unsigned char version3;
	unsigned char version4;
	unsigned char version5;
	unsigned short ver6;
	unsigned int ver7;
	unsigned int ver8;
};

struct info_t
{
	unsigned char version;
	unsigned char version1;
	unsigned char version2;
	unsigned char version3;
	unsigned char version4;
	unsigned char version5;
	unsigned short ver6;
	unsigned int ver7;
	unsigned int ver8;
};


void test_union(void)
{
	printf("sizeof(info_u) = %d ,sizeof(info_t) = %d\n", sizeof(union info_u), sizeof(struct info_t));// 结果是4和16
}
