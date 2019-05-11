// this version of countzeroes traverses the array backwards.
// you may find the loop code is simpler if you start with this version.
// NOTE: the simple machine DEC instruction still wont do you any good.
// (the printf statement is just here for testing)
// to compile and run: cc countzeroesdec.c 
//                     ./a.out
//
const int N=10;
int ia[] = { 0,1,3,443,-9,0,0,34,-128,0 };
int main(){ 
    int nz=0;
    int i;
    for (i=(N-1); i>=0; i--) {
       if (ia[i] == 0) nz++;
    }
    printf("%d\n",nz);
}

