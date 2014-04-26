#include <iostream>
#include <stack>
#include <list>
using namespace std;

template <typename T>
class Btree
{
private:
	struct Node
	{
		T value;
		Node * left;
		Node * right;
	};
	int size;
	Node * root;
	Node * Find_helper(T element)
	{
		if(size == 0)
		{
			return nullptr;
		}
		Node * current = root;
		while(current != nullptr)
		{
			if(current->value == element)
			{
				return current;
			}
			else if(element > current->value)
			{
				if(current->right == nullptr)
				{
					return current;
				}
				else
				{
					current  = current->right;
				}
			}
			else if(element < current->value)
			{
				if(current->left == nullptr)
				{
					return current;
				}
				else
				{
					current  = current->left;
				}
			}
		}
		return current;
	}
public:
	Btree();
	~Btree();
	void Insert(T element);
	bool Find(T element);
	void DFS(){
		stack<Node *> dfs;
		dfs.push(root);
		Node * current ;
		while(dfs.size()!= 0){
			current = dfs.top();
			dfs.pop();
			if(current->right != nullptr)
				dfs.push(current->right);
			if(current->left != nullptr)
				dfs.push(current->left);
			cout<<current->value<<"  " ;
		}
	}
	void BFS(){
		queue<Node *> BFS;
		BFS.push(root);
		Node * current ;
		while(BFS.size()!= 0){
			current = BFS.front();
			BFS.pop();
			if(current->left != nullptr)
				BFS.push(current->left);
			if(current->right != nullptr)
				BFS.push(current->right);
			cout<<current->value<<"  " ;
		}
	}
};

template <typename T>
Btree<T>::Btree()
{
	root = nullptr;
	size = 0;
}

template <typename T>
Btree<T>::~Btree()
{
	stack<Node*> s;
	s.push(root);
	while (s.size()!=0)
	{
		Node* current = s.top();
		s.pop();
		if(current->left != nullptr)
		{
			s.push(current->left);
		}
		if(current->right != nullptr)
		{
			s.push(current->right);
		}
		delete current;
		--size;
	}
}

template <typename T>
void Btree<T>::Insert(T element)
{
	Node * m = Find_helper(element);
	if(size == 0)
	{
		root = new Node();
		root->value = element;
		size++;
	}
	else if(m->value == element)
	{
		return;
	}
	else if(element > m->value)
	{
		Node * n = new Node();
		n->value = element;
		m->right = n;
		size++;
	}
	else if(element < m->value)
	{
		Node * n = new Node();
		n->value = element;
		m->left = n;
		size++;
	}
}

template <typename T>
bool Btree<T>::Find(T element)
{
	if(Find_helper(element)->value == element)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main()
{
	Btree<int> bt;
	bt.Insert(10);
	bt.Insert(5);
	bt.Insert(15);
	bt.Insert(3);
	bt.Insert(7);
	bt.Insert(20);
	bt.Insert(6);
	bt.Insert(8);
	bt.Insert(17);
	bt.Insert(25);
	for(int C=0;C<=30;C++)
	{
		cout << bt.Find(C) << " " << C << endl;
	}

	}