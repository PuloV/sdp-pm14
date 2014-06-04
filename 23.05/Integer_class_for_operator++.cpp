#include<iostream>
using namespace std;

class Integer {
	int x;
public:
	Integer(int v){ x = v;}
	void print() {cout << x << endl; }
	Integer operator++(int){
		x++;
		return *(new Integer(x-1));
	}

	Integer operator++(){
		x++;
		return *this;
	}
};

int main(){
	Integer x(5);
	Integer y = x++;

	x.print();
	y.print();

	Integer z = ++y;
	z.print();
	y.print();

	int a = 5;
	cout<<endl<<(++a)++;
	cout<<endl<<a<<endl;
}