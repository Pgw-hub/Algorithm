#include <iostream>

using namespace std;

int main(){

    int N, M;
    int D = 0;

    cin >> N >> M;

    while(N--){
        D++;
        if(D % M == 0){
            N++;
        }
    }

    cout << D << endl;

    return 0;    

}