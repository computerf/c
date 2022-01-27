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
	cout << "老板编号:" << this->m_Id
		<< "\t老板姓名:" << this->m_Name
		<< "\t岗位:" << this->GetDeptName()
		<< "\t岗位职责:下发任务给经理" << endl;
}

string  Boss::GetDeptName()
{
	return string("老板");
}