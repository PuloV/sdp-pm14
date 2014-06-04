// Да се добавят проверки когато поп-ваме от празна опашка а също и empty method
#include<iostream>
using namespace std;

template <class T>
class Queue
{
  struct Node
  {
    T value;
    Node *next;
  }*begin , *end ;
  int size;

public:
  Queue(){ this->begin = this->end = nullptr ; size = 0;}
  Queue(Queue &);
  T pop() {
  Node *to_delete = this -> begin;
  T returned_value = to_delete->value;
  begin = begin->next;
  delete to_delete;
  this->size--;
  return returned_value;

}

  const Queue<T> &operator=(Queue &rhs){
  while(!this->is_empty()) this->pop();
    if(rhs.begin == nullptr) return *(new Queue);
    Node * top_element =rhs.begin ;
    while(top_element != nullptr){
      this->push(top_element->value);
      top_element = top_element->next;
    }
    return *this;
  }
  void push(T new_value){
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
  ~Queue(){ while (!this->is_empty()) this->pop(); }

};

int main()
{
  Queue<int> myQ;
  for(int i = 0 ; i< 6 ; i++)
      myQ.push(i);
  for(int i = 0 ; i< 6 ; i++)
    cout<<myQ.pop()<<"  ";
  cout<<endl;
  Queue<char> myChars,my_new_Chars;
  for(char i = 'a' ; i<= 'z' ; i++)
      myChars.push(i);
  my_new_Chars = myChars;
  while(!my_new_Chars.is_empty())
    cout<<my_new_Chars.pop()<<"  ";
  cout<<endl;
  return 0;
}