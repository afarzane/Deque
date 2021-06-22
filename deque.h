#pragma once
#include <string>

using namespace std;


class deque
{
public:
	
	int studentCount = 0;
	string student_number;
	string fullname;
	deque* next;
	deque* prev;
	deque* rear;
	deque* front;

	deque();
	void pushFront(string name, string id);
	void pushRear(string name, string id);
	void clear();
	void display();
	bool isEmpty();
	int count();
	string popFront();
	string popRear();
	string peekFront();
	string peekRear();
	
};

