
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
	//��������������ܲ�����const�ͱ���
	const int num = 10;
	int number = 10, num2 = 9;

	//�����ܲ�����char��short
	char num_c = 9;
	short num_s = 9;

	//int array[num] = { 0 };	//�������벻��
	//int array2[number] = { 0 };//����Ҳ���벻��
	//int array3[foo()] = { 0 };//����Ҳ���벻��

	int array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int temp = array[num2];//������array�Ѷ���֮���ʹ�á�

	int array2[10];
	int temp2 = array2[num2];//������array�Ѷ���֮���ʹ�á�

	int temp3 = g_array[num2];//������array�Ѷ���֮���ʹ�á�

	int temp4 = array[num_c];//˵��������±������char�ͱ�����
	int temp5 = array[num_s];//˵��������±������short�ͱ�����


	//���ۣ�����ͳ�ʼ����ʱ���������ﲻ���ñ�����������ֵ��
	//����������Ѷ��壬��ڶ���ʹ�õ�ʱ����ԡ�(����֮����Բ���ʼ������Ȼ�ֲ������ᱻ��ʼ��ΪһЩ���̶���ֵ)

	temp = sub_fun(array, 5);
}