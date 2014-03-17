#include<iostream>
#include<string>
#include <vector>
using namespace std;

class Person {
	char name[100],gender[1];
	int egn;
protected:
	void hello(){cout<<"HELLO"<<endl;}
public:
	Person(){cout<<"EMPTY"<<endl;}
	Person(int e){
		egn = e;
		strcpy(name , "HELLO ! ");
		strcpy(gender , " ");
	}
	Person(char *n, int e, char *g) {
		strcpy(name , n);
		egn = e;
		strcpy(gender ,g);
	}
	char* get_name(){return name;}
	void set_name(char * n) { strcpy(name , n);}
	void set_egn(int e) {egn = e;}
	int get_egn(){return egn;}

};
class Employee : public Person {
	char job[100];
	int income;
public:
	Employee(char *n,int egn,char *g,char *j, int inc):Person(n,egn,g){
		strcpy(job , j);
		income =inc;
		this->hello();
	}
};

class Firm
{
public:
	void add_employee(Employee *new_employee){
		staff.push_back(new_employee);
	}

private:
	vector<Employee*> staff;
};


int main(){

	char name[7] = "dancho" ;
	char gender[2] = "m";
	char job[8] = "teacher";
	//Person me(name,921020,gender);
	Employee me2(name,921020,gender,job,0);
	Firm myFirm;
	for(int i=0; i<4;i++){
		Employee me3(name,921020,gender,job,i);
		myFirm.add_employee(&me3);}


	cout<<me2.get_egn()<<" "<<me2.get_name();

	return 0;
}