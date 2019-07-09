/*
来源：https://blog.csdn.net/zhourunan123/article/details/81048764
快速排序的基本思想是：递归加交换
PS:既然涉及到递归，就要小心栈溢出
*/


int partition(int arr[], int low, int high)
{
	int base = arr[low];
	while (low < high)
	{
		while (low < high && arr[high] >= base)// 从右向左找小于base的数
		{
			high--;
		}
		swap(&arr[low], &arr[high]);
		while (low < high && arr[low] <= base)// 从左向右找大于base的数
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

