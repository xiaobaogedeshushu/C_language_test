



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
	case 0:          //跳转开始
		for (i = 0; i <= 5; i++)
		{
			//DelayX(20);
			//lc = 79;
			lc = __LINE__;
			printf("i=%d\r\n", i);
			return;
	//case 79:这样写可以
	//case __LINE__://这样写会报错，提示case后面要跟常量
		Wait;
		printf("79\r\n");
		}

	}; lc = 0;  //跳转结束
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