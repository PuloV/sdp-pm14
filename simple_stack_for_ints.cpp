// 123.cpp : Defines the entry point for the console application.
//
#include <cmath>
#include "stdafx.h"
#include <iostream>
using namespace std;

class Stack
{

public:

	void push(int );
	int pop();
	Stack();
	~Stack();

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
	int value;
	do 
	{
		value=this->pop();
	}

	while (value!=-1);

}

int _tmain(int argc, _TCHAR* argv[])
{
	Stack myS;
	int value;
	cin>>value;

	while (value!=-1)
	{
		myS.push(value);
		cin>>value;
	}

	int temp = myS.pop();

	while(temp != -1)
	{
		cout<<temp<<" ";
		temp = myS.pop();
	}

	system("pause");
	return 0;
}

