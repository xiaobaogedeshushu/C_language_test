#include <stdlib.h>
#include "main.h"






void test_qsort(void)
{

//����stdlib���qsort����
	qsort(g_array_backups, sizeof(g_array_backups) / sizeof(int), sizeof(int), compar);

}