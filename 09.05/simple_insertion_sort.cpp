#include <iostream>
#include<vector>
using namespace std;

struct Choco
{
	int ymd;
	char name[100];
};

int main()
{
	int n,d,m,y,ymd;
	char name[100];
	cin>>n;
	vector<Choco> myChoco;
	cin>>d>>m>>y>>name;
	ymd = y*10000+m*100+d;
	Choco temp;
	temp.ymd=ymd;
	strcpy(temp.name,name);
	myChoco.push_back(temp);
	for(int i=1;i<n;i++){
		cin>>d>>m>>y>>name;
		ymd = y*10000+m*100+d;
		Choco temp;
		temp.ymd=ymd;
		strcpy(temp.name,name);
		myChoco.push_back(temp);
		int j = i;*/
		while(j>0 && myChoco[j].ymd > myChoco[j-1].ymd){
			swap(myChoco[j-1],myChoco[j]);
			j--;
		}
	}

	for(int i=0;i<n;i++)
		cout<<myChoco[i].ymd<<" "<<myChoco[i].name<<endl;
}