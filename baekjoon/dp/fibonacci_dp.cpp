#include <iostream>

using namespace std;

typedef struct {
    
    int zero = 0;
    int one = 0;

} CNT;

//bottom up
void fibonacci(int n,CNT* fib) {

    fib[0].zero = 1;
    fib[1].one = 1;

    for(int i = 2; i <= n; i++){
        fib[i].zero = fib[i-1].zero + fib[i-2].zero;
        fib[i].one = fib[i-1].one + fib[i-2].one;
    }

}

int main(){
    int a;
    int N; 

    cin >> a;

    while(a--){
    
        CNT fib[41]; 
        cin >> N;
        fibonacci(N,fib);
        cout << fib[N].zero << " " << fib[N].one << endl;

    }
    return 0; 
}
