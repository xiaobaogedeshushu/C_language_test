#include <stdio.h>
#include <afx.h>

int main()
{
#if 0
	//CString result = (L"[2017/10/11-13:41:49] > get_gsm_signal()\r\nAT+CSQ\r\n\r\n+CSQ: 14, 99\r\n\r\nOK\r\n[2017/10/11-13:41:49] get_bat_percent,votalge=4183469\r\nyy");
	CString result = (L"AT+CSQ\r\n\r\n+CSQ: 99, 99\r\n\r\nOK\r\n");
	CString ATCSQReply	= (L"AT+CSQ\r\n\r\n+CSQ: ");
	CString Temp1, Temp2;
	//Temp1 = result.Mid(0 + 16).Left(2);
	Temp1 = result.Mid(0 + 16,2);
#endif
	//CString input = _T("BT KEY:,,\r\n[2018 / 01 / 19 - 14:05 : 25] sim:1 gsm register : 1 ip : 255 sms : 1.gprs register : 1 active : 1 connect : 2. \r\n");
	CString input = _T("BT KEY:123,,789\r\n[2018 / 01 / 19 - 14:05 : 25] ,sim:1\r\n");
	CString strBTKeyWord = _T("BT KEY:"), strTempBlueTooth = _T(""), strBTNum1 = _T(""), strBTNum2 = _T(""), strBTNum3 = _T("");
	int nTagBlueKey = 0, nCurPos1 = 0;
	nTagBlueKey = input.Find(strBTKeyWord, 0);
	if (nTagBlueKey >= 0)
	{
		strTempBlueTooth = input.Mid(nTagBlueKey + strBTKeyWord.GetLength());
		if (strTempBlueTooth != (_T("")))
		{
			strBTNum1 = strTempBlueTooth.Tokenize(_T(",\n"), nCurPos1);
			if (strBTNum1 == _T("\r"))
			{	
				strBTNum1 = _T("0");
				strBTNum2 = _T("0");
				strBTNum3 = _T("0");
				return 0;
			}
			strBTNum2 = strTempBlueTooth.Tokenize(_T(","), nCurPos1);
			strBTNum3 = strTempBlueTooth.Tokenize(_T("\r\n"), nCurPos1);
		}
	}
	return 0;
}
