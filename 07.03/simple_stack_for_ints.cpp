#include <iostream>
using namespace std;

class Stack
{

public:

	void push(int );
	int pop();
	Stack();
	~Stack();
	bool is_empty() {return (top == nullptr);}

private:

	struct Node
	{
		int value;
		Node *prev;
	};

	Node *top;
	int count;

};

Stack::Stack()
{
	top=nullptr;
	count=0;
}

void Stack::push(int element)
{
	Node *temp=new Node;
	temp->value=element;
	temp->prev=top;
	count++;
	top=temp;
}
int Stack::pop()
{
	if(count==0)
	{
		return -1;
	}

	int p= top->value;
	Node *todelete=top;
	top = top->prev;

	delete todelete;
	count--;
	return p;
}

Stack::~Stack()
{
	while (!this->is_empty());
	{
		this->pop();
	}


}

int main()
{
	Stack myS;
	int value;
	cin>>value;

	while (value!=-1)
	{
		myS.push(value);
		cin>>value;
	}



	while (!myS.is_empty())
	{
		cout<<myS.pop()<<" ";
	}
	system("pause");
	return 0;
}

