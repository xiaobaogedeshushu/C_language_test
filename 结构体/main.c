#include <stdio.h>

void test_const(void);
int test_struct_typedef_const();
void test_sizeof(void);

int main()
{
	test_struct_typedef_const();
	test_const();
	test_sizeof();
	test1_sizeof();

	return 0;
}


/*
@brief:test_struct_typedef_const
@param  I:
		O:
@return
@author Kevin
@date   2018
@version v1.0
@note  :��Ҫ���Թؼ��֣�typedef����ϵĹؼ��֣�const struct
*/
int test_struct_typedef_const()
{
	typedef struct Student
	{
		int num;
	}Typedef_Stu, *Typedef_Stu_pst;

	const Typedef_Stu stu1 = { 1 };
	Typedef_Stu stu2 = { 2 };
	const struct Student stu3 = { 3 };

	//stu1.num = 2;	//const���������˵������������һ�����ͨ��������Ϊstu1 is not a modifiable value

	const Typedef_Stu_pst stu_pst1 = &stu1;

	//stu_pst1 = &stu2;//��һ��Ҳ���벻������Ϊstu_pst1 is not a modifiable value��˵�� stu_pst1�������ֻ�ܷŹ̶����ڴ��ַ�������ַ���ܱ䡣

	const struct Student *stu_pst2 = &stu2;

	stu_pst2 = &stu1;//�����Ա���ͨ����˵����һ���const���ε���ָ�롣��ַ�ɱ䣬��Ӧ��ַ��ı������ܱ䡣
	//stu1.num = 11;//�����Ա���ͨ��,˵��stu1��Ӧ��ַ��ı������ܱ䡣
	return 0;
}




