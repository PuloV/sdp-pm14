#include<iostream>
#include<string>
#include <typeinfo>

using namespace std;
template<class TemplateType>
void Print_with_newline(TemplateType variable)
{

	if(typeid(variable) == typeid(int))
		printf("Result of integers is: %d \n" ,variable );
	else if( typeid(variable) == typeid(double) ||  typeid(variable) == typeid(float) )
		{   if( typeid(variable) == typeid(double))
			     printf("Result of doubles  is: %f \n" ,variable );
			else   printf("Result of floats is: %f \n" , variable );
		}
	else if(typeid(variable) == typeid(string))
			cout<<"Result of string is : "<< variable <<endl;
		else printf("Result of chars is: %s \n" ,variable);
	//cout<<variable<<endl;
}
int main()
{
	int new_int_num =5;
	float new_float_num = 5.25;
	double new_double_num = 5.256789;
	Print_with_newline<int>(new_int_num);
	Print_with_newline<double>(new_double_num);
	Print_with_newline<char*>("This is CHAR *");
	Print_with_newline<string>("This is STRING");
	Print_with_newline<float>(new_float_num);
	return 0;
}