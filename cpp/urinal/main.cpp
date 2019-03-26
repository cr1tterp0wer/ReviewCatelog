#include<iostream>

using namespace std;

void printArr( char * u, int len ){
  
  for( int i = 0; i < len; i++ ){
    cout << u[i];
  }
  cout << endl;
}

void disperse( char * u, int len, int population ){

  int start, end, tmpStart, tmpEnd;
  int biggestSize, currentSize;
  
  start = end = tmpStart = tmpEnd = 0;
  biggestSize = currentSize = 0;

  u[0] = 'X';
  population--;
  u[len-1] = 'X';
  population--;

  while( population > 0 ){
    
    for( int i = 0; i < len; i++ ){
      
      if( u[i] == 'o'){
        currentSize++;
      }else{

       if( currentSize > biggestSize){
         printArr( u, len);
         biggestSize = currentSize;
         end = i;
         start = tmpStart;
       }

       currentSize = 0;
       tmpStart = i;
      }
    }
   
     u[ ( start + ( end - start ) / 2) ] = 'X';
     biggestSize = currentSize = 0;
     start = tmpStart = 0;
     end   = tmpEnd   = 0;
     population--;
  }
}

int main(){
  
  char  urinals[10] = { 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o' };

  disperse( urinals, 10, 10 ); 
  printArr( urinals, 10 );

  return 0;
}
