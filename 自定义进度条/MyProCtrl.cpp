#include "stdafx.h"
#include "MyProCtrl.h"


CMyProCtrl::CMyProCtrl()
{
	m_ColText = RGB(255, 0, 0);//文本颜色
	m_ColProgress = RGB(0, 255, 255);//进度条颜色
	m_ColBlank = RGB(192, 192, 192);//空白区域颜色

}


CMyProCtrl::~CMyProCtrl()
{
}
BEGIN_MESSAGE_MAP(CMyProCtrl, CProgressCtrl)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMyProCtrl::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CProgressCtrl::OnPaint() for painting messages

	PAINTSTRUCT ps;//声明一个绘画区域
	CDC *pDC = BeginPaint(&ps);//把绘画区域选入设备上下文并开始
	int AdrPos = GetPos();//获取进度条的进度位置
	CString StrPos;//声明字符串，用于显示进度条的进度
	StrPos.Format(_T("%d%%", AdrPos));//把进度位置复制到StrPos
	CRect ClientRC;
	GetClientRect(&ClientRC);//获取客户区矩形
	CSize CsText = pDC->GetTextExtent(StrPos);//获取显示StrPos的规模大小
	int nX = (ClientRC.Width() - CsText.cx) / 2;//获取显示字符串的X
	int nY = (ClientRC.Height() - CsText.cy) / 2;//获取显示字符串的Y
	pDC->SetBkMode(TRANSPARENT);//设置背景模式为透明
	int nMin, nMax;//声明进度条的最大最小限制
	GetRange(nMin, nMax);//获取限制
	double Every = (double)ClientRC.Width() / (nMax - nMin);//获取单位刻度
	int Now = Every*AdrPos;//当前长度
	CRect LeftRC, RightRC;//声明进度条区域和空白区域
	LeftRC = RightRC = ClientRC;
	LeftRC.right = Now;//进度条区域
	RightRC.left = Now;//空白区域
	pDC->FillRect(LeftRC, &(CBrush)m_ColProgress);//画进度条区域
	pDC->FillRect(RightRC, &(CBrush)m_ColBlank);//画空白区域
	pDC->SetTextColor(m_ColText);//设置文本颜色
	//pDC->TextOutA(nX, nY, StrPos);//写文本
	pDC->TextOutW(nX, nY, StrPos);//写文本
	ReleaseDC(pDC);//销毁设备上下文
	EndPaint(&ps);//结束绘画区域绘画
}
