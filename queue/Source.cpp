#include <iostream>
using namespace std;
const int Max_Size = 100;
template <class t>
class CircularArrayQueue
{
private:
	int front;
	int rear;
	int length;
	t queue[Max_Size];
public:
	CircularArrayQueue()
	{
		front = 0;
		rear = Max_Size - 1;
		length = 0;
	}
	bool isempty()
	{
		return length == 0;
	}
	bool isfull()
	{
		return length == Max_Size;
	}
	void enqueue(t element)
	{
		if (isfull())
			cout << "The queue if full.";
		else
		{
			rear = (rear + 1) % Max_Size;
			queue[rear] = element;
			length++;
		}	

	}
	void dequeue()
	{
		if (isempty())
			cout << "Queue is already empty.";
		else
		{
			front = (front + 1) % Max_Size;
			length--;
		}
	}
	t frontqueue()
	{
		if (isempty())
			cout << "Queue is empty.";
		else
			return queue[front];
	}
	t rearqueue()
	{
		if (isempty())
			cout << "Queue is empty.";
		else
			return queue[rear];
	}
	void printqueue()
	{
		if (!isempty())
		{
			for (int i = front; i != rear; i = (i + 1) % Max_Size)
				cout << queue[i] << " ";
			cout << queue[rear] << endl;
		}
		else
			cout << "Queue is empty.";
		
	}
	
};

template <class t>
class LinkedQueue
{
private:
	struct Node
	{
		t item;
		Node* next;
	};
	Node  *front;
	Node  * rear;
	int length;
public:
	LinkedQueue()
	{
		front = NULL;
		rear = NULL;
		length = 0;
	}
	bool isempty()
	{
		return length == 0;
	}
	void enqueue(t element)
	{
		if (isempty())
		{
			front = new Node;
			front->item = element;
			front->next = NULL;
			rear = front;
			length++;
		}
		else
		{
			Node *newnode = new Node;
			newnode->item = element;
			newnode->next = NULL;
			rear->next = newnode;
			rear = newnode;
			length++;
		}
	}
	void dequeue()
	{
		if (isempty())
			cout << "Queue is already empty." << endl;
		else
		{
			Node* temp = front;
			if (front == rear)
			{
				front = rear = NULL;
				length--;
			}
			else
			{
				front = front->next;
				length--;
			}
			temp->next = NULL;
			delete temp;
		}
	}
	t getfront()
	{
		if (isempty())
			cout << "Queue is empty.";
		else
			return front->item;
	}
	t getrear()
	{
		if (isempty())
			cout << "Queue is empty.";
		else
			return rear->item;
	}
	int getsize()
	{
		return length;
	}
	void clear()
	{
		Node* curr;
		while (front != NULL)
		{
			curr = front;
			front = front->next;
			delete curr;
		}
		rear = NULL;
		length = 0;
	}
	void printqueue()
	{
		Node* curr = front;
		while (curr != NULL)
		{
			cout << curr->item << " ";
			curr = curr->next;
		}
		cout << endl;
	}
};

int main()
{
	LinkedQueue <double>x;
	x.enqueue(5.2);
	x.enqueue(8.5);
	x.enqueue(2.6);
	x.enqueue(7.7);
	x.enqueue(59.6);
	x.printqueue();
	x.dequeue();
	x.printqueue();

}