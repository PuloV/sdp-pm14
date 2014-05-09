#include <iostream>
#include<vector>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class Tree
{
	struct Node
	{
		T value;
		vector<Node*> children;
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
			/*for(vector<Node*>::iterator it = current->children.begin();it != current->children.end(); ++it)
			{
				s.push(*it);
			}*/
			for(int i=0 ; i< (current->children.size()) ;i++)
				s.push(current->children[i]);
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
		for(int i = 0 ; i< (current->children).size() ;i++)
		{
			s.push(current->children[i]);
		}
		delete current;
	}
}

template <class T>
void Tree<T>::Insert(const T & val,const T & pos)
{
	Node * temp = Find(pos);
	if(temp == nullptr)
	{
		Node * n = new Node();
		n->value = val;
		if(root != nullptr)
		{
			n->children.push_back(root);
		}
		root = n;
	}
	else
	{
		Node * c = new Node();
		c->value = val;
		temp->children.push_back(c);
	}
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
		for (int i = 0 ; i< (tmp->children).size() ;i++ )
		{
			q.push(tmp->children[i]);
			cout<<tmp->children[i]->value<<" ";
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