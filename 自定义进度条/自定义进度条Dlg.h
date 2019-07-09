
// 自定义进度条Dlg.h : header file
//

#pragma once
#include "MyProCtrl.h"
#include "afxcmn.h"
#include "TextProgressCtrl.h"


// CcustomProCtrlDlg dialog
class CcustomProCtrlDlg : public CDialogEx
{
// Construction
public:
	CcustomProCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTextProgressCtrl m_ProCtrl;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedOk();
	CProgressCtrl m_progctril3;
};
