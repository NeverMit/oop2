#include <iostream>
#include <string.h>
using namespace std; 
class Human {
public:
	string name;
	int age;
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
	Human(const Human &h)
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
};
int main()
{
	Human* h1 = new Human;
	Human* h2 = new Human("Denis", 20);
	Human* h3 = new Human(*h2);
	delete h1;
	delete h2;
	delete h3;

}