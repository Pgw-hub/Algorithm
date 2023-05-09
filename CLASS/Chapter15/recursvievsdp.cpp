#include <stdio.h>
#include <time.h>

long long rec_fib(int n);
long long dp_fib(int n);
long long mem_dp_fib(int n,long long list[]);


int count;

int main(){
    int i,n,r;
    long long res;
    float gap;
    time_t startT=0; 
    time_t endT=0;

    printf("Enter positive integer: ");
    scanf("%d",&n);

    long long list[n+1];
    for(i=0;i<=n;i++) list[i]=false;

    startT=clock();
    res = dp_fib(n);
    endT = clock();
    gap = (float) (endT-startT) / (CLOCKS_PER_SEC);
    printf("\n dp time : %12.10f\n", gap);

    startT=clock();
    res = rec_fib(n);
    endT = clock();
    gap = (float) (endT-startT) / (CLOCKS_PER_SEC);
    printf("\n rec time : %12.10f\n", gap);
 
}



long long dp_fib(int n){
    int i;
    long long fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(i=2;i<=n;i++)
        fib[i] = fib[i-1] + fib[i-2];
    return fib[n];
}

long long rec_fib(int n){
    if(n<2)
        return n;
    else
        return rec_fib(n-1) + rec_fib(n-2);
}


