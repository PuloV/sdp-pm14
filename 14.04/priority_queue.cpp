#include<iostream>
using namespace std;
template<class T>
class priority_queue
{
public:
	priority_queue(){
		this->first=this->last = nullptr;
		size = 0;
	}

	~priority_queue(){
		while(!this->is_empty())
			this->pop();
	}

	 priority_queue&  push(T value){
		Node *new_node = new Node;
		new_node->value = value;
		if(this->is_empty()){
			new_node->next = nullptr;
			this->first = this->last = new_node;
			this->size++;
			return *this;
		}

		if(value < this->first->value){
			new_node->next = this->first;
			this->first = new_node;
			this->size++;
			return *this;
		}

		if(value > this->last->value){
			new_node->next = nullptr;
			this->last->next  = new_node;
			this->last = new_node;
			this->size++;
			return *this;
		}

		Node * loop = this->first;
		while (value > loop->next->value)
		{
			loop = loop->next;
		}
		new_node->next = loop->next;
		loop->next = new_node;
		this->size++;
		return *this;
	}
	T pop(){
		Node *to_delete = this->first;
		T val = to_delete->value;
		this->first = this->first->next;
		this->size--;
		delete to_delete;
		return val;
	}
	bool is_empty(){return (size == 0);}

private:
	struct Node
	{
		T value;
		Node *next;
	};
	Node *first , *last;
	int size;
};

int main(){
	priority_queue<int> pq;
	pq.push(0).push(3).push(1).push(2);

	while(!pq.is_empty())
		cout<<pq.pop()<<endl;
}