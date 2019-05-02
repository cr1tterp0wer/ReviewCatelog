
#include<iostream>
using namespace std;

int solveCounter( int n ){
  
  int total = 2;
  for ( int i = 0 ; i < n; i++){
    total *= 2;
  }
  return total;
}

int main(){

  cout << "let's go" << endl;
  cout << solveCounter( 20 );

  return 0;
}
