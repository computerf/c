#define _CRT _SECURE_NO_ WARNINGS 1
#include"Manger.h"

Manger::Manger(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Manger::showInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->GetDeptName()
		<< "\t��λְ��:����ϰ彻��������" << endl;
}

string Manger::GetDeptName()
{
	return string("����");
}