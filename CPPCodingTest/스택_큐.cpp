#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

class Stack
{
public:
	Node* head;
	Stack()
	{
		head = nullptr;
	}
	void push(int data)
	{
		Node* newData = new Node;
		newData->data = data;
		newData->link = head;
		head = newData;
	}
	int pop()
	{
		if (head == nullptr)
		{
			return -1;
		}
		else
		{
			int data;
			Node* temp = head;
			data = temp->data;
			head = temp->link;
			delete temp;
			return data;
		}
	}
};

class Queue
{
public:
	Node* front;
	Node* end;
	Queue()
	{
		front = nullptr;
		end = nullptr;
	}
	void Enqueue(int data)
	{
		Node* newData = new Node;
		newData->data = data;
		newData->link = nullptr;

		if (front == nullptr)
		{
			front = newData;
		}
		else
		{
			end->link = newData;
		}
		end = newData;
	}

	int Dequeue()
	{
		if (front == nullptr)
		{
			return -1;
		}
		else
		{
			Node* temp = front;
			int data = temp->data;
			front = temp->link;
			if (front == nullptr)
			{
				end = nullptr;
			}
			delete temp;
			return data;
		}
	}
};

int main(void)
{
	Stack stack;
	stack.push(1);
	cout << stack.pop();

	Queue queue;
	queue.Enqueue(1);
	cout << queue.Dequeue();
	return 0;
}