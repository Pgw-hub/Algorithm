#include <iostream>

using namespace std;

#define SIZE 30
int main(){
    int N, M, i, j, T;
    int DP[SIZE][SIZE] = {0};

    cin >> T;
    
    while(T--){

        cin >> N >> M;
        for(i =1; i<=M; i++){
            DP[1][i] = i;
        }

        for(i=2; i<= N; i++){
            for(j =2; j<=M; j++){
                DP[i][j] = DP[i-1][j-1] + DP[i][j-1];
            }
        }
        cout << DP[N][M] << endl;
    }
}