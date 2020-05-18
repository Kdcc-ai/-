#include<iostream>
#include<string>
using namespace std;
/*
Teacher类
*/
class Teacher
{
public:
	Teacher(string name, int age, char sex, string addr,string tel);
	void display();
protected:
	string name;
	int age;
	char sex;
	string addr;
	string tel;
};
Teacher::Teacher(string name, int age, char sex, string addr,string tel)
{
	this->name = name; this->age = age;
	this->sex = sex; 
	this->addr = addr; this->tel = tel;
}
void Teacher::display()
{
	cout << "name " << name << endl;
	cout << "age "  << age << endl;
	cout << "sex "  << sex << endl;
	cout << "address " << addr << endl;
	cout << "telephone " << tel << endl;
}
/*
Cadre类
*/
class Cadre
{
public:
	Cadre(string name, int age, char sex, string addr, string tel, string post);
	void display();
protected:
	string name;
	int age;
	char sex;
	string addr;
	string tel;
	string post;
};
Cadre::Cadre(string name, int age, char sex, string addr, string tel, string post)
{
	this->name = name; this->age = age;
	this->sex = sex;
	this->addr = addr; this->tel = tel;
	this->post = post;
}
void Cadre::display()
{
	cout << "name " << name << endl;
	cout << "age " << age << endl;
	cout << "sex " << sex << endl;
	cout << "address " << addr << endl;
	cout << "telephone " << tel << endl;
	cout << "post " << post << endl;
}
/* 
子类 Teacher_Cader类
*/
class Teacher_Cader :public Teacher, public Cadre
{
public:
	Teacher_Cader(string name, int age, char sex, string addr, string tel, string post,float wage);
	void show();
private:
	float wage;
};
Teacher_Cader::Teacher_Cader(string name, int age, char sex, string addr, string tel, string post,float wage):
	Teacher(name,age,sex,addr,tel),Cadre(name,age,sex,addr,tel,post),wage(wage){}
void Teacher_Cader::show()
{
	Teacher::display();
	cout << "post " << post << endl;
	cout << "wage " << wage << endl;
}
/*
主函数
*/
int main()
{
	Teacher_Cader Example1("铁蛋", 21, 'm', "abc", "13243695438", "Cook", 8000);
	Teacher_Cader Example2("枸杞", 20, 'w', "abc", "13243695438", "Agent", 18000);
	Example1.show();
	Example2.show();
	system("pause");
}

