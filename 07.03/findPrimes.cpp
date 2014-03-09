#include <iostream> 
using namespace std; 
class findPrimes{ 
    int upto; 
public: 
    findPrimes(int ); 
    //~findPrimes(); 
    void show_result(); 
private: 
    bool Prime(int ); 
}; 
findPrimes::findPrimes(int x) 
{upto=x;} 
void findPrimes::show_result(){ 
    for(int i=2;i<upto;i++) 
        if(Prime(i)) cout<<i<<" ";} 
bool findPrimes::Prime(int y){ 
    for(int i=2;i<y;i++) 
        if(y%i==0) 
        { 
            return false; 
        } 
        return true;} 
int main(){ 
    int n; 
    cin>>n; 
    findPrimes stuff(n); 
    stuff.show_result(); 
    return 0; 
} 