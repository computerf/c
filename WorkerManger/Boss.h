#pragma once
#include"worker.h"
class Boss : public Worker
{
public:
	 Boss (int id, string name, int dId);//���캯��

	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};