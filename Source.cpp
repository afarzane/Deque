#include <iostream>
#include <string>
#include "deque.h"

using namespace std;

int main()
{
	deque classA;

	classA.clear();

	classA.pushFront("Amirali", "11");
	classA.pushFront("Shay", "22");
	classA.pushFront("Meg", "33");
	classA.pushRear("Daniel", "44");
	classA.display();

	cout << endl;

	cout << classA.count() << endl; 

	cout << endl;

	classA.popFront();
	classA.popRear();
	classA.display();

	cout << endl;

	cout << classA.peekFront() << endl;
	cout << classA.peekRear() << endl;

	cout << classA.count() << endl;

	classA.pushRear("Meg", "33");
	classA.display();

	classA.clear();

	classA.display();

	classA.popFront();
	classA.popRear();

	cout << classA.peekFront() << endl;
	cout << classA.peekRear() << endl;

	cout << classA.count() << endl;

	cout << endl;

	classA.pushFront("Amirali", "11");
	classA.pushFront("Shay", "22");
	classA.pushRear("Sam", "50");
	classA.pushFront("Meg", "33");
	classA.pushRear("Daniel", "44");
	classA.display();

	cout << classA.count() << endl;

	system("pause");
	return 0;
}
