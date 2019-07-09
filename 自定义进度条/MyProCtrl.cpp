#include "stdafx.h"
#include "MyProCtrl.h"


CMyProCtrl::CMyProCtrl()
{
	m_ColText = RGB(255, 0, 0);//�ı���ɫ
	m_ColProgress = RGB(0, 255, 255);//��������ɫ
	m_ColBlank = RGB(192, 192, 192);//�հ�������ɫ

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

	PAINTSTRUCT ps;//����һ���滭����
	CDC *pDC = BeginPaint(&ps);//�ѻ滭����ѡ���豸�����Ĳ���ʼ
	int AdrPos = GetPos();//��ȡ�������Ľ���λ��
	CString StrPos;//�����ַ�����������ʾ�������Ľ���
	StrPos.Format(_T("%d%%", AdrPos));//�ѽ���λ�ø��Ƶ�StrPos
	CRect ClientRC;
	GetClientRect(&ClientRC);//��ȡ�ͻ�������
	CSize CsText = pDC->GetTextExtent(StrPos);//��ȡ��ʾStrPos�Ĺ�ģ��С
	int nX = (ClientRC.Width() - CsText.cx) / 2;//��ȡ��ʾ�ַ�����X
	int nY = (ClientRC.Height() - CsText.cy) / 2;//��ȡ��ʾ�ַ�����Y
	pDC->SetBkMode(TRANSPARENT);//���ñ���ģʽΪ͸��
	int nMin, nMax;//�����������������С����
	GetRange(nMin, nMax);//��ȡ����
	double Every = (double)ClientRC.Width() / (nMax - nMin);//��ȡ��λ�̶�
	int Now = Every*AdrPos;//��ǰ����
	CRect LeftRC, RightRC;//��������������Ϳհ�����
	LeftRC = RightRC = ClientRC;
	LeftRC.right = Now;//����������
	RightRC.left = Now;//�հ�����
	pDC->FillRect(LeftRC, &(CBrush)m_ColProgress);//������������
	pDC->FillRect(RightRC, &(CBrush)m_ColBlank);//���հ�����
	pDC->SetTextColor(m_ColText);//�����ı���ɫ
	//pDC->TextOutA(nX, nY, StrPos);//д�ı�
	pDC->TextOutW(nX, nY, StrPos);//д�ı�
	ReleaseDC(pDC);//�����豸������
	EndPaint(&ps);//�����滭����滭
}
