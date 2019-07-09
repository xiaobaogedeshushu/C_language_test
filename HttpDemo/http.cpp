//文件描述:使用HTTP GET 下载文件
//
//*/
//
//#include "stdafx.h"
//#include <afxinet.h> //定义了MFC CInternetSession类等     
//#include <iostream>
////	
//CInternetSession *pInetSession = new CInternetSession(	AfxGetAppName(),1, PRE_CONFIG_INTERNET_ACCESS);
//
//CHttpConnection *pHttpConn = NULL;
//CHttpFile *pHttpFile = NULL;
////CString strUrl;
//DWORD dwServiceType;
//CString strServer, strObj, strUser, strPwd;
//INTERNET_PORT nPort;
//
//CString strUrl = _T("http://agnss-server-1.wh-mx.com:32101/v1/device/agnss?client_id=test&device_id=test&protocol=whmx&data_type=eph&gnss=gps,bds&pos=30.50,114.39");
//
//if (!AfxParseURLEx(strUrl, dwServiceType, strServer, strObj, nPort, strUser, strPwd, ICU_NO_ENCODE))
//{
//	MessageBox("下载地址有错!");
//	return;
//}
//if (!pHttpConn)
//{
//	pHttpConn = pInetSession->GetHttpConnection(strServer, INTERNET_INVALID_PORT_NUMBER, "ELIMINATOR77", "PANZER76");
//}
//
//int nVal = 6000;
//
//pInetSession->SetOption(INTERNET_OPTION_CONNECT_TIMEOUT, &nVal, sizeof(nVal));
//pHttpFile = pHttpConn->OpenRequest("GET", strObj);
//try
//{
//	MessageBox(_T("正在连接到网站..."));
//	pHttpFile->SendRequest();
//}
//catch (CInternetException *pEx)
//{
//	MessageBox(_T("下载出错..."));
//	pEx->Delete();
//	delete pHttpFile;
//	return;
//}
//
//
//
//