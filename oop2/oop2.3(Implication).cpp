#include <iostream>
#include <string.h>
using namespace std;
class Human {
protected:
	string name;
	int age;
public:
	Human()
	{
		cout << "Human()\n";
		name = "Artem";
		age = 20;

	}
	Human(string name, int age)
	{
		cout << "Human(string name, int age)\n";
		this->name = name;
		this->age = age;
	}
	Human(const Human& h)
	{
		cout << "Human(const Human &h)\n";
		name = h.name;
		age = h.age;
	}
	~Human()
	{
		cout << name << " " << age << "\n";
		cout << "~Human()\n";

	}
	void addAge(int newAge)
	{
		age += newAge;
	}
	void changeName();
};
void Human::changeName()
{
	name = "Sasha";
}
class Student:public Human {
protected:
	string faculty;
public:
	Student() :Human()
	{
		cout << "Student()\n";
		faculty = "";

	}
	Student(string name,int age,string faculty):Human(name,age)
	{
		cout << "Student(string name, int age,string faculty)\n";
		this->faculty = faculty;
		
	}
	Student(const Student& h)
	{
		cout << "Student(const Student &h)\n";
		faculty = h.faculty;
		name = h.name;
		age = h.age;
	}
	~Student()
	{
		cout << name << " " << age <<" faculty = "<<faculty<< "\n";
		cout << "~Student()\n";

	}
	void changeFaculty(string newFaculty)
	{
		faculty = newFaculty;
	}
};
int main()
{
	Student* s = new Student("Artem",20,"FIRT");
	
	delete s;
}