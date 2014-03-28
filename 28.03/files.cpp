#include <iostream>
#include<fstream>
using namespace std;
int main(){
  //copy ints
  ifstream INPUT;
  ofstream OUTPUT;
  OUTPUT.open("test2.txt");
  INPUT.open("test1.txt");
  int temp;
  while(INPUT>>temp){
    OUTPUT<<" "<<temp;
  }

// read the numbers
  fstream FILE;
  FILE.open("story.txt");
  char word;
  bool flag = false;
  while(!FILE.eof())
  {
    FILE>>word;
    if((word - '0') <= 9 && (word - '0') >= 0){
      cout<<word;
    flag = true;
  }
  else if(flag)
    { cout<<endl;
  flag = false;}
  }
  return 0;
}
