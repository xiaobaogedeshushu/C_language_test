
/*
test_unsigned
�����ʽ�д����з������ͺ��޷�������ʱ���еĲ��������Զ�ת��Ϊ�޷������͡�
���-20�����һ���ǳ���������������Ըñ��ʽ������Ľ������6��
��һ�����Ƶ���õ��޷����������͵�Ƕ��ʽϵͳ��Ӳ���Ĵ�����ֵȫ�����޷��ŵģ���˵�Ƿ᳣��Ҫ�ġ�
*/
void test_unsigned(void)
{
	unsigned int a = 6;

	int b = -20;

	(a + b > 6) ? puts("> 6") : puts("<= 6");//����Ǵ���6
}




//ֻȡ��N��Bit�Ĳ��������д��



//������ʵ�����׻���sizeof()��strlen()������strlen()�����ַ����ĳ���
//���a[i] = 0,���ӡ��Ӧ�������±ꡣ
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
	printf("sizeof(info_u) = %d ,sizeof(info_t) = %d\n", sizeof(union info_u), sizeof(struct info_t));// �����4��16
}
