#pragma once
#include "afxcmn.h"
class CMyProCtrl :
	public CProgressCtrl
{
public:
	CMyProCtrl();
	~CMyProCtrl();


	COLORREF m_ColText;//�ı���ɫ
	COLORREF m_ColProgress;//��������ɫ
	COLORREF m_ColBlank;//�հ�������ɫ
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

