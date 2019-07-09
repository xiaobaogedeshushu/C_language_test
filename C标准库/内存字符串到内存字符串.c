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
	/*	上述3行代码说明：
	1、snprintf最后的参数（来源），可以是字符串或字符;
	2、snprintf第二个参数，不仅要算上“来源”的有效字符，
	更要记得加上作为字符串自动带的'\0',所以要加1，所以写成 sizeof(str)是比较保险的。
	3、snprintf等于拷贝的有效字符的数量，不包括'\0'	*/


	char test[8]; 
	int ret2 = snprintf(test, 5, "1234567890");
	printf("%d|%s\n", ret, test);
	/*	结果为：
	ret2为10
	test为1234

	上述2行代码说明：
	1、snprintf的参数可以是3个，只要来源是字符串即可。
	2、ret等于源字符串长度,而非实际拷贝，也不包括'\0',	
	3、实际拷贝的长度的最大值是：size-1和源字符串长度的最小值。
	*/

	char test_2[8];
	int ret3 = snprintf(test_2, 8, "1234567890");//第二个参数大于目标的最大值会出错，如果第二个参数小于或等于源的长度，则目标会在结尾自动补'\0'
	//int ret3 = sprintf(test_2, "1234567890");//可以这么写，但如果和下面一行一起用，会导致出错，因为字符串要用'\0'结尾。
	//printf("%d|%s\n", ret3, test_2);

}
