/*
@brief:test_const
@param  I:
O:
@return
@author Kevin
@date   2019
@version v1.0
@note  :主要测试关键字：const，配合的关键字或知识点：指针
*/


void test_const(void)
{
const int a = 15, c = 16;
int b,d = 17;
const int * p;
int * const prt = &a;
const int * const point = &d;
p = &a;  //合法，p指向只读变量
p = &b;    //合法，p指向变量
//*p = 14;  //不合法，不能通过p间接地修改它所指向的量.编译会出错。

//prt = &c;//不合法，这个指针的值不能改变了。
*prt = 14;//合法，可以通过指针改变指针指向的地址存放的数据。

//*point = 14;//不合法，不能通过p间接地修改它所指向的量
//point = &c;//不合法，这个指针的值不能改变了
d = 14;//合法
int e = *point;//合法



}