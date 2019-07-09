#include <stdlib.h>
#include "main.h"






void test_qsort(void)
{

//²âÊÔstdlib¿âµÄqsortº¯Êý
	qsort(g_array_backups, sizeof(g_array_backups) / sizeof(int), sizeof(int), compar);

}