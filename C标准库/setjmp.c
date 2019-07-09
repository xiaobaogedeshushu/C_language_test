/*
与abort()和exit()相比,goto语句看起来是处理异常的更可行方案。
不幸的是，goto是本地的：它只能跳到所在函数内部的标号上，而不能将控制权转移到所在程序的任意地点
（当然，除非你的所有代码都在main体中）。
为了解决这个限制，C函数库提供了setjmp()和longjmp()函数，它们分别承担非局部标号和goto作用。
*/
#include <stdio.h>
#include <setjmp.h>

jmp_buf jumper;

int div(int a, int b) {
	if (b == 0) { // can't divide by 0
		longjmp(jumper, -3);//跳到以jumper 所在的jmp point，进行处理，-3 相当于具体的exception code.
	}
	return a / b;
}


/*
函数名：test_setjmp
执行的结果是：
test_goto
goto来到这里
6/2=3
分析：setjmp的作用之一是可以实现一个函数的执行结果，而又不会占用返回值或者参数。
*/
void test_setjmp(int a, int b) {
	int jstatus = setjmp(jumper);//相当于java catch,如果发生 jumper 异常，那么会跳回到这个jmp point
	if (jstatus == 0) {//第一次执行的时候是正确的setjmp return 0.

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
goto只能在一个函数里跳转.
*/
void test_goto(void)
{
	printf("test_goto\n");
	goto TAG;

TAG:
	printf("goto来到这里\n");
}
