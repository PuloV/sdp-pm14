// Да се добавят проверки когато поп-ваме от празна опашка а също и empty method
#include<iostream>
using namespace std;

template <class T>
class List
{
  struct Node
  {
    T value;
    Node *next;
  }*begin , *end ;
  int size;

public:
  List(){ this->begin = this->end = nullptr ; size = 0;}
  List(List &);
  T pop_front() {
  Node *to_delete = this -> begin;
  T returned_value = to_delete->value;
  begin = begin->next;
  delete to_delete;
  this->size--;
  return returned_value;
  }

  T pop_back() {
  Node *to_delete = this -> end;
  Node *temp = this->begin;
  for(int i=1 ; i<this->size-1 ; i++)
	  temp = temp->next;
  T returned_value = to_delete->value;
  this->end = temp;
  delete to_delete;
  this->size--;
  return returned_value;
  }

  const List<T> &operator=(List &rhs){
    if(rhs.begin == nullptr) return *(new List);
    Node * top_element =rhs.begin ;
    while(top_element != nullptr){
      this->push(top_element->value);
      top_element = top_element->next;
    }
    return *this;
  }
  void push_front(T new_value){
  Node *new_node = new Node;
  new_node->value = new_value;

  if(this->is_empty())
  {
    new_node->next = nullptr;
    this->begin = this->end = new_node;
  this->size++;
    return ;
  }
  new_node -> next = this->begin;
  this->begin = new_node;
  this->size++;
  }
  void push_back(T new_value){
  Node *new_node = new Node;
  new_node->value = new_value;

  if(this->is_empty())
  {
    new_node->next = nullptr;
    this->begin = this->end = new_node;
  this->size++;
    return ;
  }
  new_node -> next = nullptr;
  this->end->next = new_node;
  this->end = new_node;
  this->size++;
}
  bool is_empty() {return (this->size == 0); }
  ~List(){ while (!this->is_empty()) this->pop_front(); }

};

int main()
{
 List<int> myList;
 for(int i=0; i<11;i++)
 {
	 myList.push_back(i);
 }

 while(!myList.is_empty())
 {
	 cout<<myList.pop_front()<<" "<<myList.pop_back()<<endl;
 }
 return 0;
}