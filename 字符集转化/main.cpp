#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

//-------------------------------------------------------------------------------------
//Description:
//		This function maps a character string to a wide-character (Unicode) string
//作者:	Kevin
//Parameters:
//		ptStr: [out] Pointer to a buffer that receives the translated string. 
//		pdwResSize: [out]  the number of translated string
//		lpcszStr: [in] Pointer to the character string to be converted 
//		dwSize:[in] Size of the character string
//Return:
//		0: Succeed
//		负数: Failed		(-1:分配的TCHAR型数组长度小于转换后需要的长度)
//---------------------------------------------------------------------------------------
INT32  MByteToWChar(PTCHAR ptStr, PDWORD  pdwResSize, LPCSTR lpcszStr, DWORD dwSize)
{
	// Get the required size of the buffer that receives the Unicode  string. 
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, NULL, 0);

	if (dwSize < dwMinSize)
		return  -1;//如果分配的TCHAR型数组长度小于转换后需要的长度, 则返回错误代码-1

	MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, ptStr, dwMinSize);
	*pdwResSize = dwMinSize;
	return 0;//成功返回0,因为C语言的main 函数成功也返回0
}

//-------------------------------------------------------------------------------------
//Description:
//		This function maps a wide-character string to a new character string
//作者:	Kevin
//Parameters:
//		lpszStr: [out] Pointer to a buffer that receives the translated string. 
//		pdwResSize: [out]  the number of translated string
//		ptStr:[in]  Pointer to the character string to be converted 
//		dwSize: [in] Size of the buffer
//Return:
//		0: Succeed
//		负数: Failed		(-1:分配的char型数组长度小于转换后需要的长度)
//---------------------------------------------------------------------------------------
INT32  WCharToMByte(LPSTR lpszStr, PDWORD  pdwResSize, PTCHAR ptStr, DWORD dwSize)
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_OEMCP, NULL, ptStr, -1, NULL, 0, NULL, FALSE);
	if (dwSize < dwMinSize)	
		return -1;//如果分配的char型数组长度小于转换后需要的长度, 则返回错误代码-1
	
	WideCharToMultiByte(CP_OEMCP, NULL, ptStr, -1, lpszStr, dwSize, NULL, FALSE);
	*pdwResSize = dwMinSize;
	return  0;//成功返回0,因为C语言的main 函数成功也返回0
}


int main()
{
	TCHAR *tText= _T("函数示例");	
	char sText[20] = { 0 };
	DWORD dwLengthOfMByte = 0;
	WCharToMByte(sText, &dwLengthOfMByte, tText, sizeof(sText) / sizeof(sText[0]));
	printf("%s\n%ld\n", sText, dwLengthOfMByte);
	return 0;
}