



#if 0
#include <stdio.h>

#define Wait case:__LINE__

static char i;

void   subtask()
{
	//        static char i;
	static int lc = 0;

	//lc=79;
	switch (lc)

	{
	case 0:          //��ת��ʼ
		for (i = 0; i <= 5; i++)
		{
			//DelayX(20);
			//lc = 79;
			lc = __LINE__;
			printf("i=%d\r\n", i);
			return;
	//case 79:����д����
	//case __LINE__://����д�ᱨ����ʾcase����Ҫ������
		Wait;
		printf("79\r\n");
		}

	}; lc = 0;  //��ת����
				//        return i;

}

int main(int argc, char* argv[])
{
	char ii = 0;
	char b = 0;

	while (b<5)
	{
		b++;
		printf("ii=%d\r\n", i);
		subtask();
	}

	printf("Hello World!\n");
	system("pause");
	return 0;
}
#endif