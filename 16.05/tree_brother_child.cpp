#include<iostream>
#include<queue>
using namespace std;

template<class T>
class Tree
{
private:
	struct Node
	{
		T value;
		Node *child , *brother;
	}  *root;
	Node * Find( T parent){
		queue<Node *> search_queue;
		search_queue.push(root);
		while (search_queue.size() !=0 )
		{
			Node *current = search_queue.front();
			search_queue.pop();
			if(current->value == parent)
				return current;
			if(current->brother != nullptr)
				search_queue.push(current->brother);
			if (current->child != nullptr)
				search_queue.push(current->child);
		}
		return root;
	}
public:
	Tree(){ root = nullptr;}
	void Insert(T val , T parent){
		if(root == nullptr)
		{
			root = new Node;
			root->value = val;
			root->child = root->brother = nullptr;
			return;
		}

		Node *par = Find(parent);
		Node *new_node = new Node;
		new_node->value = val;
		new_node->child = new_node->brother = nullptr;
		if(par->child == nullptr)
		{
			par->child = new_node;
		}
		else
		{
			Node * p_child = par->child;
			while(p_child->brother != nullptr)
				p_child = p_child->brother;
			p_child->brother = new_node;
		}
	}

};

int main(){
	Tree<int> tr;
	tr.Insert(1,0);
	tr.Insert(2,1);
	tr.Insert(3,1);
	tr.Insert(4,2);
	tr.Insert(5,2);
	tr.Insert(6,2);
	tr.Insert(7,3);
	tr.Insert(8,3);
	tr.Insert(9,2);
}