#include<iostream>
using namespace std;

const int SIZE = 10;

void descending( int n ){

  if( n < 0)
    return;
  cout << n << endl;
  descending( n - 1 );
}

void ascending( int n ){

  if( n < 0 )
    return;
  ascending( n - 1 ) ;
  cout << n << endl;
}

int main(){

  descending( SIZE );
  ascending( SIZE );
  return 0;
}


