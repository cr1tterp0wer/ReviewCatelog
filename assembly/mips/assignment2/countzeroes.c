// this version of countzeroes traverses the array forwards.
// (the printf statement is just here for testing)
// to compile and run: cc countzeroes.c 
//                     ./a.out
//
const int N=10;
int ia[] = { 0,1,3,443,-9,0,0,34,-128,0 };
int main(){ 
    int nz=0;
    int i;
    for (i=0; i<N; i++) {
       if (ia[i] == 0) nz++;
    }
    printf("%d\n",nz);
}

