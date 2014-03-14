// Да се добавят проверки когато поп-ваме от празна опашка а също и empty method
#include<iostream>
using namespace std;

class Queue
{
  struct Node
  {
    int value;
    Node *next;
  };
  Node *begin , *end ;
  int size;

public:
  Queue(){ begin = end = nullptr ; size = 0;}
  Queue(Queue &);
  int pop();
  void push(int&);
 const Queue & operator=(Queue &rhs);
  bool is_empty() {return (size == 0); }
  ~Queue(){ while (!this->is_empty()) this->pop(); }

};

const Queue & Queue::operator=(Queue &rhs){
  if(rhs.begin == nullptr) return *(new Queue);
  Node * top_element =rhs.begin ;
  while(top_element != nullptr){
    this->push(top_element->value);
    top_element = top_element->next;
  }
  return *this;
}

void Queue::push(int &new_value){
  Node *new_node = new Node;
  new_node->value = new_value;
  new_node->next = nullptr;
  if(this->is_empty())
  {
    begin = end = new_node;

  }
  else {
  end->next = new_node;
  end = new_node;
  }
  size++;
}


int Queue::pop()
{
  Node *to_delete = this -> begin;
  int returned_value = to_delete->value;
  begin = begin->next;
  delete to_delete;
  size--;
  return returned_value;

}

int main()
{
  Queue myQ,q2;

  for(int i = 0 ; i< 6 ; i++)
      myQ.push(i);
  cout<<"OUTPUT"<<endl;

  myQ.is_empty();

  q2 = myQ;

  for(int i = 0 ; i< 6 ; i++){
    cout<<q2.pop()<<" " ;}
  cout<<endl;
  return 0;
}