
int g_array[10];

int foo(void)
{
	return 10;

}

int sub_fun(int* arr,int num)
{
	return arr[num];
}


void test_array(void)
{
	//测试数组的容量能不能用const型变量
	const int num = 10;
	int number = 10, num2 = 9;

	//测试能不能用char和short
	char num_c = 9;
	short num_s = 9;

	//int array[num] = { 0 };	//这样编译不过
	//int array2[number] = { 0 };//这样也编译不过
	//int array3[foo()] = { 0 };//这样也编译不过

	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int temp = array[num2];//这样是array已定义之后的使用。

	int array2[10];
	int temp2 = array2[num2];//这样是array已定义之后的使用。

	int temp3 = g_array[num2];//这样是array已定义之后的使用。

	int temp4 = array[num_c];//说明数组的下标可以用char型变量。
	int temp5 = array[num_s];//说明数组的下标可以用short型变量。


	//结论：定义和初始化的时候，中括号里不能用变量或函数返回值，
	//但是如果是已定义，则第二次使用的时候可以。(定义之后可以不初始化，虽然局部变量会被初始化为一些不固定的值)

	temp = sub_fun(array, 5);
}