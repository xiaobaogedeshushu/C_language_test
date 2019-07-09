



/*
函数名：select_Sort
作用：选择排序，（升序）
*/
void select_sort(int array[], int length) {
	int i, j, min;

	for (i = 0; i<length-1; i++) 
	{
		min = i;//以首元素为第一个基准

		for (j = i + 1; j<length-1; j++) 
		{
			if (array[min] > array[j])
			{
				//若有小于基准的值，则更换基准
				min = j;
			}
		}
		if (i != min) 
		{
			//若min与i不相等，则说明找到这趟排序的最小值，交换。如果相等，则这趟排序第一个数就是最小值，所以不用动。
			swap(&array[min], &array[i]);
		}
	}
}




void select_sort_20190622(int array[], int count)
{
	int i, j, min;

	for (i = 0; i < count-1; i++)
	{
		min = i;//以首元素为基准
		for (j = i+1; j < count-1 ; j++)
		{
			if (array[min] < array[j])
			{
				min = j;
			}		
		}
		if(i != min)
		{
			swap(&array[min], &array[i]);
		}
	}	
}





