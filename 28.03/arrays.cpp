#include <iostream>
using namespace std;

int factorial(int n) {
  int fact=1;
  for (int i=1; i<=n; i++)
    fact*=i;
  return fact;
}

int main(){
  // Array
  int *facts;
  int n;
  cin>>n;
  facts = new int[n]; // Creates a new array with n elements
  for(int i =0; i<n; i++)
    facts[i] =factorial(i);
  for(int i =1; i<=n; i++)
    cout<<facts[n-i]<<" ";

  // Matrix
  double **Matrix;
  int m;
  cin>>n>>m;
  Matrix = new double *[n];
  for (int i = 0; i < n; ++i)
  {
    Matrix[i] = new double[m];
  }

  return 0;
}