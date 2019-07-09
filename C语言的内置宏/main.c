#include <stdio.h>
#include "subfun.h"

void print_macro(void)
{
	printf("File = %s\nLine = %d\nDate = %s\nTime = %s\n",
	__FILE__,__LINE__,__DATE__,__TIME__);//Function = %s\n  __FUNCTION__

}

int main()
{
#if 0

	//int a = __LINE__;
	//printf("%d", __LINE__);
	//printf("%d", a);
	print_macro();
	
	//printf("MAX=%d",MAX);//±àÒë²»Í¨¹ý
	int result;
	Calculat(pin_state, 5, &result);
	printf("result:%d\r\n",result);
	FUNC;
	
#endif
	test_define();
	getchar();
	return 0;
}

