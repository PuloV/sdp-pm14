#include<iostream>
#include <string>
using namespace std;

class Animal{
	char name[100];
public:
	Animal(char *n){
		strcpy(name,n);
	}
	virtual char* eating_sound()
	{ return "Yom Yom"; }

	virtual void says_hello()
	{
		printf("Hi there , I am %s " , name);
	}

	void eat()
	{
		says_hello();
		printf(" and I am eating .. \n %s \n %s \n Really tasty ! \n", eating_sound(),eating_sound());
	}
};

class Cat : public Animal {
public:
	Cat(char *name):Animal(name){

	}
	virtual char* eating_sound()
	{ return "Miau Miau"; }
};


class Dog : public Animal {
public:
	Dog(char *name):Animal(name){

	};

	 char* eating_sound()
	{ return "Nom Nom"; }
};

class Doberman : public Dog {
public:
	Doberman(char *name):Dog(name){

	};

	 char* eating_sound()
	{ return "Grr Grr"; }
};

int main()
{
	Animal Az("Az");
	Az.eat();
	cout<<endl;
	Cat c("Pussy cat");
	c.eat();
	cout<<endl;
	Dog d("Doggy Dog");
	d.eat();

	cout<<endl;
	Doberman dd("Evil Doggy Dog");
	dd.eat();
}