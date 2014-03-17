#include<iostream>
#include<stack>
#include<queue>

using namespace std;
int main(){
	int n;
	cin>>n;
	stack<int> my_digits;
	queue<char> my_chars;
	for(int i =0 ; i<n;i++){
	int digit ;
	cin>>digit;
	my_digits.push(digit);
	}
	for(int i =0 ; i<n-1;i++){
	char symb;
	cin>>symb;
	my_chars.push(symb);
	}

	while(!my_chars.empty())
	{
		int first = my_digits.top();
		 my_digits.pop();
		int second = my_digits.top();
		  my_digits.pop();
		char do_it = my_chars.front();
		my_chars.pop();
		if(do_it == '+')
			my_digits.push(first + second);
		if(do_it == '-')
			my_digits.push(first - second);
		if(do_it == '*')
			my_digits.push(first * second);
		if(do_it == '/')
			my_digits.push(first / second);

	}

	cout<<my_digits.top();

	return 0;
}