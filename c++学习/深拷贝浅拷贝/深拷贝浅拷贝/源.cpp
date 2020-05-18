#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class  Name
{
public:
	Name(const char *myp)
	{
		m_len = strlen(myp);
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, myp);
	}

	//�������: �ֹ��ı�д�������캯�� ʹ����copy
	Name(const Name& obj1)
	{
		m_len = obj1.m_len;
		m_p = (char *)malloc(m_len + 1);
		strcpy(m_p, obj1.m_p);
	}

    Name& operator=(Name &obj1) // ���صȺ������
    {
		//���ͷžɵ��ڴ�
	    if (this->m_p != NULL)
	    {
	        delete[] m_p;
	        m_len = 0;
	    }
		//2 ����obj1�����ڴ��С
	    this->m_len = obj1.m_len;
	    this->m_p = new char [m_len+1];

		//��obj1��ֵ
	    strcpy(m_p, obj1.m_p);
	    return *this;
	}
	~Name()
	{
		if (m_p != NULL)
		{
			free(m_p);
			m_p = NULL;
			m_len = 0;
		}
	}
private:
	char *m_p;
	int m_len;
};

//����������ʱ�� ����coredump
void objplaymain()
{
	Name obj1("abcdefg");
	Name obj2 = obj1;

	Name obj3("obj3");
	obj3 = obj1;

	obj1 = obj2 = obj3;
	//obj2.operator=(obj3);
	//obj1 = void;
}

int main()
{
	objplaymain();
	cout << "hello..." << endl;
	system("pause");
	return 0;
}