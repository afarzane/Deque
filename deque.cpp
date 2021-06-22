#include "deque.h"
#include <iostream>
#include <string>
#include <new>

using namespace std;

deque::deque()
{
	rear = NULL;
	front = NULL;
}

void deque::pushFront(string name, string id)
{
	try
	{
		deque* node = new deque;
		node->fullname = name;
		node->student_number = id;
		node->next = NULL;
		node->prev = NULL;
		if (isEmpty())
		{
			front = rear = node;
			studentCount++;
		}
		else
		{
			node->next = front;
			front->prev = node;
			front = node;
			studentCount++;
		}
	}
	catch (bad_alloc& badAlloc)
	{
		cout << "pushFront() failed! Bad alloc: " << badAlloc.what() << endl;
	}
}

void deque::pushRear(string name, string id)
{
	try
	{
		deque* node = new deque;
		node->fullname = name;
		node->student_number = id;
		node->next = NULL;
		node->prev = NULL;
		if (isEmpty())
		{
			front = rear = node;
			studentCount++;
		}
		else
		{
			node->prev = rear;
			rear->next = node;
			rear = node;
			studentCount++;
		}
	}
	catch (bad_alloc& badAlloc)
	{
		cout << "pushRear() failed! Bad alloc: " << badAlloc.what() << endl;
	}
}

void deque::clear()
{
	try
	{
		if (isEmpty())
		{
			throw 6;
		}
		else
		{
			while (!isEmpty())
			{
				if (front == rear)
				{
					deque* temp = front;
					front = rear = NULL;
					delete temp;
					studentCount--;
				}
				else
				{
					deque* temp = front;
					front = temp->next;
					delete temp;
					studentCount--;
				}
			}
		}
	}
	catch(int)
	{
		cout << "Deque is empty. Nothing to clear." << endl;
	}
}

bool deque::isEmpty()
{
	if (front == NULL && rear == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void deque::display()
{
	deque* curr = front;
	try
	{
		if (isEmpty())
		{
			throw 5;
		}
			
		while (curr != rear)
		{
			cout << "Student name: " << curr->fullname << ", Student ID: " << curr->student_number << endl;
			curr = curr->next;
		}

		if (curr == rear)
		{
			cout << "Student name: " << curr->fullname << ", Student ID: " << curr->student_number << endl;
		}
	}
	catch (int)
	{
		cout << "Deque is empty! Nothing to display." << endl;
	}
}

string deque::popFront()
{
	try
	{
		if (isEmpty())
		{
			throw 1;
		}
		else if(front == rear)
		{
			deque* temp = front;
			front = rear = NULL;
			string tempID = temp->student_number;
			string tempName = temp->fullname;
			delete temp;
			studentCount--;
			return tempID, tempName;
		}
		else
		{
			deque* temp = front;
			string tempID = temp->student_number;
			string tempName = temp->fullname;
			front = temp->next;
			front->prev = NULL;
			studentCount--;
			return tempID, tempName;
		}
	}
	catch (int)
	{
		cout << "Deque is empty! nothing to pop." << endl;
		return "Error";
	}
	catch (bad_alloc& badAlloc)
	{
		cout << "popFront() failed! Bad alloc: " << badAlloc.what() << endl;
		return "Error";
	}
}

string deque::popRear()
{
	try
	{
		if (isEmpty())
		{
			throw 2;
		}
		else if (front == rear)
		{
			deque* temp = rear;
			front = rear = NULL;
			string tempID = temp->student_number;
			string tempName = temp->fullname;
			delete temp;
			studentCount--;
			return tempID, tempName;
		}
		else
		{
			deque* temp = rear;
			rear = temp->prev;
			rear->next = NULL;
			string tempID = temp->student_number;
			string tempName = temp->fullname;
			delete temp;
			studentCount--;
			return tempID, tempName;
		}
	}
	catch (int)
	{
		cout << "Deque is empty! nothing to pop." << endl;
		return "Error";
	} 
	catch (bad_alloc& badAlloc)
	{
		cout << "popRear() failed! Bad alloc: " << badAlloc.what() << endl;
		return "Error";
	}
}

string deque::peekFront()
{
	try
	{
		if (isEmpty())
		{
			throw 3;
		}
		else
		{
			return front->student_number, front->fullname;
		}
	}
	catch (int)
	{
		cout << "Deque is empty! Nothing to peek." << endl;
		return "Error";
	}
}

string deque::peekRear()
{
	try
	{
		if (isEmpty())
		{
			throw 4;
		}
		else
		{
			return rear->student_number, rear->fullname;
		}
	}
	catch (int)
	{
		cout << "Deque is empty! Nothing to peek." << endl;
		return "Error";
	}
}

int deque::count()
{
	return studentCount;
}