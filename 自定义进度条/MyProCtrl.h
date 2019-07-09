#pragma once
#include "afxcmn.h"
class CMyProCtrl :
	public CProgressCtrl
{
public:
	CMyProCtrl();
	~CMyProCtrl();


	COLORREF m_ColText;//文本颜色
	COLORREF m_ColProgress;//进度条颜色
	COLORREF m_ColBlank;//空白区域颜色
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

