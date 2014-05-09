#include <iostream>
#include<list>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class Tree
{
	struct Node
	{
		T value;
		list<Node*> children;
	};
	Node * root;
	Node * Find(const T& t)
	{
		if(root == nullptr)
		{
			return nullptr;
		}
		stack<Node*> s;
		s.push(root);
		while (s.size()!=0)
		{
			Node* current = s.top();
			s.pop();
			if(current->value == t)
			{
				return current;
			}
			for(list<Node*>::iterator it = current->children.begin();it != current->children.end(); ++it)
			{
				s.push(*it);
			}
			/*for(int i=0 ; i< (current->children.size()) ;i++)
				s.push(current->children[i]);*/
		}
		return nullptr;
	}
public:
	Tree();
	~Tree();
	Tree(const Tree &);
	void Insert(const T &,const T &);
	void Print();
};

template <class T>
Tree<T>::Tree()
{
	root = nullptr;
}

template <class T>
Tree<T>::~Tree()
{
	stack<Node*> s;
	s.push(root);
	while (s.size()!=0)
	{
		Node* current = s.top();
		s.pop();
		for(list<Node*>::iterator it = current->children.begin();it != current->children.end(); ++it)
		{
			s.push(*it);
		}
		delete current;
	}
}

template <class T>
void Tree<T>::Insert(const T & val,const T & pos)
{
}

template <class T>
void Tree<T>::Print()
{
	queue<Node*> q;
	q.push(root);
	cout<<root->value<<endl;
	while (q.size()!=0)
	{
		Node * tmp=q.front();
		q.pop();
		for (list<Node*>::iterator it = tmp->children.begin();it != tmp->children.end(); ++it)
		{
			q.push(*it);
			cout<<(*it)->value<<" ";
		}
		cout << endl;
	}

}

void main()
{
	Tree<int> tr;
	tr.Insert(1,0);
	tr.Insert(2,1);
	tr.Insert(3,1);
	tr.Insert(4,1);
	tr.Insert(5,2);
	tr.Insert(6,2);
	tr.Insert(7,4);
	tr.Insert(8,4);
	tr.Insert(9,4);
	tr.Insert(10,4);
	tr.Print();
}