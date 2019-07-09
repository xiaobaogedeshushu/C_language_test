#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
					PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND hwnd;				//窗口句柄
	MSG  msg;
	WNDCLASS wndclass;

	wndclass.style         = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc   = WndProc;	//标示了用于处理传递给窗口的消息的窗口过程。
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.hInstance     = hInstance;
	wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor       = LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName  = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;

	int i = 0;

	//步骤一：窗口类的注册
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
		return 0;
	}

	//步骤二：创建窗口
	hwnd = CreateWindow(szAppName,					//窗口类名称
						TEXT("The Hello Program"),	//窗口标题
						WS_OVERLAPPEDWINDOW,		//窗口风格，或称窗口格式
						CW_USEDEFAULT,				//初始x坐标
						CW_USEDEFAULT,				//初始y坐标
						CW_USEDEFAULT,				//初始x方向尺寸
						CW_USEDEFAULT,				//初始y方向尺寸
						NULL,						//父窗口句柄
						NULL,						//窗口菜单句柄
						hInstance,					//程序实例句柄
						NULL);						//创建参数
	//步骤三：在屏幕中显示窗口
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);//调用函数UpdateWindow将产生一个WM_PAINT消息


	//步骤四：程序进入消息循环
	while (GetMessage(&msg, NULL, 0, 0))//步骤五：从当前线程的消息队列中检索一个消息并填入MSG结构中
	{
		TranslateMessage(&msg);//将msg结构返传给windows，来把虚拟键消息转换为字符消息，比如A键按下,转换成WM_CHAR消息等   

		if (msg.message == WM_PAINT)
		{
			i++;
		}
		DispatchMessage(&msg);//再将msg结构传给Windows,Windows将该消息发给窗口过程,由窗口过程处理.

	}
	return msg.wParam;
}

/*
WndProcz这个函数翻译成“窗口过程”。也叫win prock。
用于处理传递给窗口的消息。
决定了窗口客户区的显示内容以及窗口如何对用户的输入做出响应。
*/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC			hdc;
	PAINTSTRUCT	ps;
	RECT		rect;

	switch (message)
	{
	case WM_CREATE:
		//PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
		return 0;

	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		
		GetClientRect(hwnd, &rect);

		DrawText(hdc, TEXT("Hello, Windows !"), -1, &rect,
				DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);

}