#define _CRT _SECURE_NO_ WARNINGS 1
#include"Boss.h"
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Boss::showInfo()
{
	cout << "�ϰ���:" << this->m_Id
		<< "\t�ϰ�����:" << this->m_Name
		<< "\t��λ:" << this->GetDeptName()
		<< "\t��λְ��:�·����������" << endl;
}

string  Boss::GetDeptName()
{
	return string("�ϰ�");
}