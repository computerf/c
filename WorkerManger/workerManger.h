#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>//��������������ļ�
#include"worker.h"
#include"employee.h"
#include"Boss.h"
#include"Manger.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std; //ʹ�ñ�׼�����ռ�

class WorkerManger {
public:
	//���캯��
	WorkerManger();

	//չʾ�˵�
	void Show_Menu();

	//�˳�����
	void exitSystem();

	//��������
	~WorkerManger();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ��

	bool m_FileIsEmpty;

	//ͳ������
	int get_EmpNum();

	//��ʼ��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();
	//�ж�ְ���Ƿ���� ��������ڷ���ְ���������λ�ã������ڷ���-1
	int IsExist(int id);

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();
 
	void Sort_Emp();

	//����ļ�
	void Clean_File();

};
