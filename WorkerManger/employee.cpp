#define _CRT _SECURE_NO_ WARNINGS 1
#include"employee.h"

//���캯��
Employee:: Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->GetDeptName()
		 << "\t��λְ��:��ɾ�����������" << endl;
}
string Employee::GetDeptName()
{
	return string("Ա��");
}