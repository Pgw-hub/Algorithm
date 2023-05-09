#include <iostream>

using namespace std;

#define SIZE 50

int dp_calculate(int N, int M,int dpc[SIZE][SIZE]);

int main(){
    int dpc[SIZE][SIZE] = {0};
    int NM[SIZE][2] = {0};
    int answer[SIZE] = {0};
    int num;

    cin >> num;

    for(int i=0; i < num; i++){
        cin >> NM[i][0] >> NM[i][1];    
    }

    for(int i=0; i < num; i++){
        cout << dp_calculate(NM[i][0],NM[i][1],dpc) << endl;
    }

    return 0;
}



int dp_calculate(int N, int M,int dpc[SIZE][SIZE]){
    
    
    for(int i = 0;; i <= N; i++){
        for(int j = 0;; j <= M; j++){
            if( i ==1 || i == j) dpc[i][j] = j;
            else if(i == 0 || j ==0) dpc[i][j] = 0;
            else dpc[i][j] = dpc[i][j-1] + dpc[i-1][j-1];
        }
    }
    return dpc[N][M];
}