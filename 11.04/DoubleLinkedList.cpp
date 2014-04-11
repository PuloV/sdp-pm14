#include<iostream>
using namespace std;

template<class T>
class DoubleLinkedList
{
	int size;
	struct Node
	{
		T value;
		Node *next , *prev;
	} *first , *last;
public:
	DoubleLinkedList(){ size = 0; first=last=nullptr;}
	bool is_empty() { return size==0; }


	void insert_before(int pos , T value){
		if(pos <= 0 || this->is_empty()){
			this->push_front(value);
			return;
		}
		if (pos > this->size){
			this->push_back(value);
			return;
		}
		Node *new_node = new Node;
		new_node->value = value;
		Node *loop = this->first;
		while(pos && loop->next != nullptr){
			loop=loop->next;
			pos --;}
		new_node->next = loop;
		new_node->prev = loop->prev;
		loop->prev->next = new_node;
		loop->prev = new_node;
		this->size++;
	}
	void insert_after(int pos , T value){
		if(pos < 0 || this->is_empty()){
			this->push_front(value);
			return ;
		}
		if (pos >= this->size){
			this->push_back(value);
			return;
		}
		this->insert_before(pos+1,value);
	}
	void push_back(T value){
		Node *new_node = new Node;
		new_node->value = value;
		if(this->is_empty()){
			new_node->next = new_node->prev = nullptr;
			this->first=this->last=new_node;
			this->size++;
			return ;
		}
		new_node->prev = this->last;
		new_node->next = nullptr;
		this->last->next = new_node;
		this->last = new_node;
		this->size ++;
	}
	void push_front(T value){
		Node *new_node = new Node;
		new_node->value = value;
		if(this->is_empty()){
			new_node->next = new_node->prev = nullptr;
			this->first=this->last=new_node;
			this->size++;
			return ;
		}
		new_node->next = this->first;
		new_node->prev = nullptr;
		this->first->prev = new_node;
		this->first = new_node;
		this->size ++;
	}
	Node * pop_nth(int pos){
		Node *loop = this->first;
		while(pos){
			pos--;
			loop = loop->next;
		}
		return loop;
	}

	void remove (int pos){
		Node * to_delete = this->pop_nth(pos);
		to_delete->prev->next = to_delete->next;
		to_delete->next->prev = to_delete->prev;
		delete to_delete;
		this->size--;
	}
	void remove(int i , int j){
		Node * first_to_delete = this->pop_nth(i);
		Node *last_before_delete = first_to_delete->prev;
		for(int k=0 ; k <=j-i ; k++)
		{
			Node * to_delete = first_to_delete;
			first_to_delete = first_to_delete->next;
			delete to_delete;
			this->size--;
		}
		last_before_delete->next = first_to_delete;
		first_to_delete->prev = last_before_delete;
	}

	T operator[](int pos){
		Node * returned = this->pop_nth(pos);
		return returned->value;
	}

};

int main()
{
	DoubleLinkedList<int> myDLL;
	myDLL.push_front(1);
	myDLL.push_back(2);
	myDLL.push_back(3);
	myDLL.insert_after(1,8);
	myDLL.remove(1 , 2);
	cout<<myDLL[0]<<endl;
	cout<<myDLL.operator[](1);
	return 0;
}