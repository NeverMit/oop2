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
int main()
{
	Human* h = new Human("Misha", 10);
	h->addAge(10);
	h->changeName();
	delete h;
}