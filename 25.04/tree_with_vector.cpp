#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int par , child;
	vector<int> tree;
	tree.resize(20);
	cin>>par;
	tree[1]=par;
	do {
		cin>>par>>child;
		if(par == 0 || child == 0) break;
		for(int i=0 ; i<tree.size(); i++)
			if(par == tree[i])
			{
				if(!tree[2*i])
					tree[2*i] = child;
				else tree[2*i +1] = child;

			}
	}
	while(par && child);

	for(int i=1;i<tree.size()/2;i++)
	if(tree[i])
		cout<<tree[i]<<" ima deca : "<<tree[2*i] << " , "<<tree[2*i+1]<<endl;

	return 0;
}