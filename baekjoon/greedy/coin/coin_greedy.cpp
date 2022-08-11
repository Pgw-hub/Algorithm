#include <iostream>
#include <vector>

using namespace std;

int main(){
    int K;
    int N;
    vector<int> A; 
    int count = 0;

    cin >> N >> K;

    for( int i = 0; i < N; i++ ){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    for(int i = N-1; i >= 0; i--){
        count = count + K/A[i];
        K = K % A[i];
        if(K == 0) break;
    }

    cout << count << endl;

}