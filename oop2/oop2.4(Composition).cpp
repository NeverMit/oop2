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
class Student :public Human {
protected:
	string faculty;
public:
	Student() :Human()
	{
		cout << "Student()\n";
		faculty = "";

	}
	Student(string name, int age, string faculty) :Human(name, age)
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
		cout << name << " " << age << " faculty = " << faculty << "\n";
		cout << "~Student()\n";

	}
	void changeFaculty(string newFaculty)
	{
		faculty = newFaculty;
	}
};
class Friend {
protected:
	Human *h1, *h2;
public:
	Friend()
	{
		cout << "Friend()\n";
		h1 = new Human;
		h2 = new Human;

	}
	Friend(string name1,int age1,string name2,int age2)
	{
		cout << "Friend(string name1,int age1,string name2,int age2)\n";
		h1 = new Human(name1, age1);
		h2 = new Human(name2, age2);
	}
	Friend(const Friend& f)
	{
		cout << "Friend(const Friend &h)\n";
		h1 = new Human(*(f.h1));
		h2 = new Human(*(f.h2));
	}
	~Friend()
	{
		//cout << name << " " << age << "\n";
		delete h1;
		delete h2;
		cout << "~Friend()\n";

	}
	
};
int main()
{
	Human* s1 = new Student("Artem", 20, "FIRT");
	Student* s2 = new Student("Pasha", 20, "FADET");
	delete s1;
	delete s2;
	cout << "-------------------------------------------------------------\n";
	Friend *f1 = new Friend;
	Friend* f2 = new Friend(*f1);
	delete f1;
	delete f2;
}