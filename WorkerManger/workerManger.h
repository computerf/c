#pragma once//防止头文件重复包含
#include<iostream>//包括输入输出流文件
#include"worker.h"
#include"employee.h"
#include"Boss.h"
#include"Manger.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std; //使用标准命名空间

class WorkerManger {
public:
	//构造函数
	WorkerManger();

	//展示菜单
	void Show_Menu();

	//退出功能
	void exitSystem();

	//析构函数
	~WorkerManger();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();
	//判断文件是否为空

	bool m_FileIsEmpty;

	//统计人数
	int get_EmpNum();

	//初始化
	void init_Emp();

	//显示职工
	void Show_Emp();
	//判断职工是否存在 ，如果存在返回职工在数组的位置，不存在返回-1
	int IsExist(int id);

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();
 
	void Sort_Emp();

	//清空文件
	void Clean_File();

};
