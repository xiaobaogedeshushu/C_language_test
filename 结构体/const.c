/*
@brief:test_const
@param  I:
O:
@return
@author Kevin
@date   2019
@version v1.0
@note  :��Ҫ���Թؼ��֣�const����ϵĹؼ��ֻ�֪ʶ�㣺ָ��
*/


void test_const(void)
{
const int a = 15, c = 16;
int b,d = 17;
const int * p;
int * const prt = &a;
const int * const point = &d;
p = &a;  //�Ϸ���pָ��ֻ������
p = &b;    //�Ϸ���pָ�����
//*p = 14;  //���Ϸ�������ͨ��p��ӵ��޸�����ָ�����.��������

//prt = &c;//���Ϸ������ָ���ֵ���ܸı��ˡ�
*prt = 14;//�Ϸ�������ͨ��ָ��ı�ָ��ָ��ĵ�ַ��ŵ����ݡ�

//*point = 14;//���Ϸ�������ͨ��p��ӵ��޸�����ָ�����
//point = &c;//���Ϸ������ָ���ֵ���ܸı���
d = 14;//�Ϸ�
int e = *point;//�Ϸ�



}