#include <iostream>

using namespace std;

int main(){
    int A[50] = {0};
    int N;
    int K;
    int count = 0;

    cin >> N >> K;

    for( int i = 0; i < N; i++ ){
        int temp;
        cin >> temp;
        A[i] = temp;
    }

    while(K!=0){
        for( int i=0; i < N; i++ ){
            if( A[i] >= K ) {
                
                if(A[i] == K) K = K-A[i];
                else K = K-A[i-1];
                
                count++;
                break;
            }
        }
    }

    cout << count;
}