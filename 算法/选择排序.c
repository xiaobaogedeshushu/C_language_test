



/*
��������select_Sort
���ã�ѡ�����򣬣�����
*/
void select_sort(int array[], int length) {
	int i, j, min;

	for (i = 0; i<length-1; i++) 
	{
		min = i;//����Ԫ��Ϊ��һ����׼

		for (j = i + 1; j<length-1; j++) 
		{
			if (array[min] > array[j])
			{
				//����С�ڻ�׼��ֵ���������׼
				min = j;
			}
		}
		if (i != min) 
		{
			//��min��i����ȣ���˵���ҵ������������Сֵ�������������ȣ������������һ����������Сֵ�����Բ��ö���
			swap(&array[min], &array[i]);
		}
	}
}




void select_sort_20190622(int array[], int count)
{
	int i, j, min;

	for (i = 0; i < count-1; i++)
	{
		min = i;//����Ԫ��Ϊ��׼
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





