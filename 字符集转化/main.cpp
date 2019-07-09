#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

//-------------------------------------------------------------------------------------
//Description:
//		This function maps a character string to a wide-character (Unicode) string
//����:	Kevin
//Parameters:
//		ptStr: [out] Pointer to a buffer that receives the translated string. 
//		pdwResSize: [out]  the number of translated string
//		lpcszStr: [in] Pointer to the character string to be converted 
//		dwSize:[in] Size of the character string
//Return:
//		0: Succeed
//		����: Failed		(-1:�����TCHAR�����鳤��С��ת������Ҫ�ĳ���)
//---------------------------------------------------------------------------------------
INT32  MByteToWChar(PTCHAR ptStr, PDWORD  pdwResSize, LPCSTR lpcszStr, DWORD dwSize)
{
	// Get the required size of the buffer that receives the Unicode  string. 
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, NULL, 0);

	if (dwSize < dwMinSize)
		return  -1;//��������TCHAR�����鳤��С��ת������Ҫ�ĳ���, �򷵻ش������-1

	MultiByteToWideChar(CP_ACP, 0, lpcszStr, -1, ptStr, dwMinSize);
	*pdwResSize = dwMinSize;
	return 0;//�ɹ�����0,��ΪC���Ե�main �����ɹ�Ҳ����0
}

//-------------------------------------------------------------------------------------
//Description:
//		This function maps a wide-character string to a new character string
//����:	Kevin
//Parameters:
//		lpszStr: [out] Pointer to a buffer that receives the translated string. 
//		pdwResSize: [out]  the number of translated string
//		ptStr:[in]  Pointer to the character string to be converted 
//		dwSize: [in] Size of the buffer
//Return:
//		0: Succeed
//		����: Failed		(-1:�����char�����鳤��С��ת������Ҫ�ĳ���)
//---------------------------------------------------------------------------------------
INT32  WCharToMByte(LPSTR lpszStr, PDWORD  pdwResSize, PTCHAR ptStr, DWORD dwSize)
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_OEMCP, NULL, ptStr, -1, NULL, 0, NULL, FALSE);
	if (dwSize < dwMinSize)	
		return -1;//��������char�����鳤��С��ת������Ҫ�ĳ���, �򷵻ش������-1
	
	WideCharToMultiByte(CP_OEMCP, NULL, ptStr, -1, lpszStr, dwSize, NULL, FALSE);
	*pdwResSize = dwMinSize;
	return  0;//�ɹ�����0,��ΪC���Ե�main �����ɹ�Ҳ����0
}


int main()
{
	TCHAR *tText= _T("����ʾ��");	
	char sText[20] = { 0 };
	DWORD dwLengthOfMByte = 0;
	WCharToMByte(sText, &dwLengthOfMByte, tText, sizeof(sText) / sizeof(sText[0]));
	printf("%s\n%ld\n", sText, dwLengthOfMByte);
	return 0;
}