#pragma once
#include"worker.h"
class Manger : public Worker
{
public:
	Manger(int id, string name, int dId);//���캯��

	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};
