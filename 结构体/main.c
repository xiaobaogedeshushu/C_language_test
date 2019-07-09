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
@note  :主要测试关键字：typedef，配合的关键字：const struct
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

	//stu1.num = 2;	//const的意义或者说限制体现在这一句编译通不过。因为stu1 is not a modifiable value

	const Typedef_Stu_pst stu_pst1 = &stu1;

	//stu_pst1 = &stu2;//这一句也编译不过，因为stu_pst1 is not a modifiable value，说明 stu_pst1这个变量只能放固定的内存地址，这个地址不能变。

	const struct Student *stu_pst2 = &stu2;

	stu_pst2 = &stu1;//这句可以编译通过，说明上一句的const修饰的是指针。地址可变，对应地址里的变量不能变。
	//stu1.num = 11;//这句可以编译通过,说明stu1对应地址里的变量不能变。
	return 0;
}




