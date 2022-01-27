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
	cout << "职工编号:" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->GetDeptName()
		<< "\t岗位职责:完成老板交给的任务" << endl;
}

string Manger::GetDeptName()
{
	return string("经理");
}