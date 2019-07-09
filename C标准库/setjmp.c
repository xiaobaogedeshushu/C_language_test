/*
��abort()��exit()���,goto��俴�����Ǵ����쳣�ĸ����з�����
���ҵ��ǣ�goto�Ǳ��صģ���ֻ���������ں����ڲ��ı���ϣ������ܽ�����Ȩת�Ƶ����ڳ��������ص�
����Ȼ������������д��붼��main���У���
Ϊ�˽��������ƣ�C�������ṩ��setjmp()��longjmp()���������Ƿֱ�е��Ǿֲ���ź�goto���á�
*/
#include <stdio.h>
#include <setjmp.h>

jmp_buf jumper;

int div(int a, int b) {
	if (b == 0) { // can't divide by 0
		longjmp(jumper, -3);//������jumper ���ڵ�jmp point�����д���-3 �൱�ھ����exception code.
	}
	return a / b;
}


/*
��������test_setjmp
ִ�еĽ���ǣ�
test_goto
goto��������
6/2=3
������setjmp������֮һ�ǿ���ʵ��һ��������ִ�н�������ֲ���ռ�÷���ֵ���߲�����
*/
void test_setjmp(int a, int b) {
	int jstatus = setjmp(jumper);//�൱��java catch,������� jumper �쳣����ô�����ص����jmp point
	if (jstatus == 0) {//��һ��ִ�е�ʱ������ȷ��setjmp return 0.

		printf("%d/%d", a, b);
		int result = div(a, b);
		printf("=%d\n", result);
	}
	else if (jstatus == -3)
		printf(" --> Error:divide by zero\n");
	else
		printf("Unhandled Error Case");
}




/*
gotoֻ����һ����������ת.
*/
void test_goto(void)
{
	printf("test_goto\n");
	goto TAG;

TAG:
	printf("goto��������\n");
}
