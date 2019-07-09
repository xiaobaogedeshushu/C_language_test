/*
��Դ��https://blog.csdn.net/zhourunan123/article/details/81048764
��������Ļ���˼���ǣ��ݹ�ӽ���
PS:��Ȼ�漰���ݹ飬��ҪС��ջ���
*/


int partition(int arr[], int low, int high)
{
	int base = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] >= base)// ����������С��base����
		{
			high--;
		}
		swap(&arr[low], &arr[high]);
		while (low < high && arr[low] <= base)// ���������Ҵ���base����
		{
			low++;
		}
		swap(&arr[low], &arr[high]);
	}
	return low;
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int base = partition(arr, low, high);
		quick_sort(arr, low, base - 1);
		quick_sort(arr, base + 1, high);
	}
}

