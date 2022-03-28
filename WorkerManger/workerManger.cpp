#define _CRT _SECURE_NO_ WARNINGS 1
#include"workerManger.h"

WorkerManger::WorkerManger()
{
	//��ʼ������
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�
	//1.�ļ�������
	if (!ifs.is_open()) {
	//	cout << "�ļ�������" << endl;
		this->m_FileIsEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	
	}
	//2.�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�����ļ�Ϊ��
	//	cout << "�ļ�Ϊ��!" << endl;
		this->m_FileIsEmpty = true;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
		
	}
	//3.���ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
//	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ�����:" << this->m_EmpArray[i]->m_Id
	//		<< "ְ������:" << this->m_EmpArray[i]->m_Name
	//		<< "���ű��:" << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}
WorkerManger::~WorkerManger()
{
	if (this->m_FileIsEmpty != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
		   }
		 }
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
  }
}

void WorkerManger::Show_Menu()
{
	cout << "********************************" << endl;
	cout << "*********  ְ������ϵͳ**********" << endl;
	cout << "********* 0.�˳�����ϵͳ*********" << endl;
	cout << "**********1.����ְ����Ϣ*******" << endl;
	cout << "**********2.��ʾְ����Ϣ********" << endl;
	cout << "**********3.ɾ����ְְ��*********" << endl;
	cout << "**********4.�޸�ְ����Ϣ********" << endl;
	cout << "**********5.����ְ����Ϣ********" << endl;
	cout << "**********��δʵ�֣�6.���ձ������*******" << endl;
	cout << "***********7.��������ĵ�*******" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

void WorkerManger::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManger::Add_Emp()
{
	cout << "���������ְ������:" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�����=ԭ����¼����+��������
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//���������
		for (int i = 0; i < addNum; i++)
		{
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��
			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
			{worker = new Employee(id, name, 1);
			break;
			}
			case 2:
			{worker = new Manger(id, name, 2);
			break;
			}
			case 3:
			{	worker = new Boss(id, name, 3);
			break;
			}
			default:
				break;
			}
			//������ְ��ְ��,���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ���ռ�
		delete[] this->m_EmpArray;
		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;
		
		cout << "�ɹ������" << addNum << "����ְ��" << endl;
		//�������ݵ��ļ�
		this->save();
		system("pause");
		system("cls");

	}

}
void WorkerManger::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�
	//��ÿһ��������д���ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs  <<this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManger::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ� ��
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

//��ʼ��Ա��
void WorkerManger::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1) //��ְͨ��
		{
			worker = new Employee(id, name, dId);
		}
	 	else if  (dId ==2) //����
		{
			worker = new Manger(id, name, dId);
		}
		else  //�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManger::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");

}

int WorkerManger::IsExist(int id)
{
	int Index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_Id ==id) {
			Index = i;
			break;
		}
		
	}
	return Index;

}

void WorkerManger::Del_Emp()
{
	if (this->m_FileIsEmpty)
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	else
	{
		cout << "��������Ҫɾ��ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index=this->IsExist(id);
		if (index != -1) //˵��ְ�����ڣ�����ɾ����indexλ����ְ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{  //����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--; //���������м�¼��Ա����
			//ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ�!" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManger::Mod_Emp() {
	if (this->m_FileIsEmpty)
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	else
	{
		int id = 0;
		cout << "��������Ҫ�޸�ְ���ı��" << endl;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "����:" << id << "��ְ������������ְ����" << endl;
			cin >> newId;
			cout << "������������:" << endl;
			cin >> newName;
			cout << "��ѡ���ְ����λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
			{	worker = new Employee(newId, newName, 1);
			break;
			}
			case 2:
			{	worker = new Manger(newId, newName, 2);
			break;
			}
			case 3:
			{	worker = new Boss(newId, newName, 3);
			break;
			}
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << this->m_EmpArray[ret]->m_DeptId << endl;
			this->save();
		}
		else
			cout << "�޸�ʧ�ܣ�Ҫ�޸ĵ�ְ��������" << endl;
	}

	system("pause");
	system("cls");

}

void WorkerManger::Find_Emp() {
	if (this->m_FileIsEmpty)
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1.��ְ����Ų���" << endl;
		cout << "2.����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id = 0;
			cout << "��������Ҫ����ְ����id" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ����" << endl;
				this->m_EmpArray[ret]->showInfo();


			}
			else
			{
				cout << "Ҫ���ҵ�ְ��������" << endl;
			}

		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�����:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ�����Ϊ" <<
						m_EmpArray[i]->m_Id
						<< "�ŵ���Ϣ����" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
				cout << "����ʧ�ܣ����޴���" << endl;
		}
	}

	system("pause");
	system("cls");
}
void WorkerManger::Sort_Emp()
{
	//����
}


void WorkerManger::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc); //ɾ���ļ������´���
		ofs.close();
		if (this->m_EmpArray != NULL)
		{//ɾ������ÿһ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}