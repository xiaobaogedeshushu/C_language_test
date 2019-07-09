

#define MACRO_SQRT(x) (x)*(x) 


/*宏定义和函数调用的不同:
有副作用的表达式，指的是表达式执行后，会改变表达式中某些变量的值.
最简单的如++i，这个表达式执行后，i的值会改变，这样的表达式是不应该在宏调用里出现的

*/
void test_define(void)
{
	int i = 2;      
	int b = MACRO_SQRT(++i);       
	printf("b = %d, i = %d\n", b, i);



}