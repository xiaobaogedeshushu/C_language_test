#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
					PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	HWND hwnd;				//���ھ��
	MSG  msg;
	WNDCLASS wndclass;

	wndclass.style         = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc   = WndProc;	//��ʾ�����ڴ������ݸ����ڵ���Ϣ�Ĵ��ڹ��̡�
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.hInstance     = hInstance;
	wndclass.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor       = LoadCursor(NULL,IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName  = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;

	int i = 0;

	//����һ���������ע��
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
		return 0;
	}

	//���������������
	hwnd = CreateWindow(szAppName,					//����������
						TEXT("The Hello Program"),	//���ڱ���
						WS_OVERLAPPEDWINDOW,		//���ڷ�񣬻�ƴ��ڸ�ʽ
						CW_USEDEFAULT,				//��ʼx����
						CW_USEDEFAULT,				//��ʼy����
						CW_USEDEFAULT,				//��ʼx����ߴ�
						CW_USEDEFAULT,				//��ʼy����ߴ�
						NULL,						//�����ھ��
						NULL,						//���ڲ˵����
						hInstance,					//����ʵ�����
						NULL);						//��������
	//������������Ļ����ʾ����
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);//���ú���UpdateWindow������һ��WM_PAINT��Ϣ


	//�����ģ����������Ϣѭ��
	while (GetMessage(&msg, NULL, 0, 0))//�����壺�ӵ�ǰ�̵߳���Ϣ�����м���һ����Ϣ������MSG�ṹ��
	{
		TranslateMessage(&msg);//��msg�ṹ������windows�������������Ϣת��Ϊ�ַ���Ϣ������A������,ת����WM_CHAR��Ϣ��   

		if (msg.message == WM_PAINT)
		{
			i++;
		}
		DispatchMessage(&msg);//�ٽ�msg�ṹ����Windows,Windows������Ϣ�������ڹ���,�ɴ��ڹ��̴���.

	}
	return msg.wParam;
}

/*
WndProcz�����������ɡ����ڹ��̡���Ҳ��win prock��
���ڴ������ݸ����ڵ���Ϣ��
�����˴��ڿͻ�������ʾ�����Լ�������ζ��û�������������Ӧ��
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