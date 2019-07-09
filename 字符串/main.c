#include <stdio.h>

int main(void)
{
#if 0
	u8 version_hex[4] = { 0x01,0x33,0xc5,0x8a };
	u8 version_dec[9];

	str_hex2str_dec(version_dec, version_hex, 4);
	printf("version_dec = %s\n", version_dec);

	char* array[] =
	{
		"ALARM_NONE",
		"ALARM_VIB",
		"ALARM_EX_PWR_OFF"

	};

	int length = sizeof(char*);
#endif
	printf("sizeof(char) = %d\nsizeof(short) = %d\nsizeof(int) = %d\nsizof(long) = %d\nsizof(long long) = %d\nsizof(float) = %d\nsizof(double) = %d\n ", 
		sizeof(char),
		sizeof(short),
		sizeof(int), 
		sizeof(long), 
		sizeof(long long),
		sizeof(float),
		sizeof(double)
	);
	//test();
	//test2();
	//test3();
	//test_unsigned();
	test_char();
	test_union();

	test_array();

	system("pause");
	return 0;
}