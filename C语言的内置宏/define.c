

#define MACRO_SQRT(x) (x)*(x) 


/*�궨��ͺ������õĲ�ͬ:
�и����õı��ʽ��ָ���Ǳ��ʽִ�к󣬻�ı���ʽ��ĳЩ������ֵ.
��򵥵���++i��������ʽִ�к�i��ֵ��ı䣬�����ı��ʽ�ǲ�Ӧ���ں��������ֵ�

*/
void test_define(void)
{
	int i = 2;      
	int b = MACRO_SQRT(++i);       
	printf("b = %d, i = %d\n", b, i);



}