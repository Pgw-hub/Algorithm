#include <iostream>

using namespace std;

#define SIZE 8

int main(){
    char t[SIZE][SIZE + 2] = {};
    int count = 0;

    for(int i = 0; i < SIZE; i++){
        cin >> t[i];
        for(int j = 0; j < SIZE + 2; j++){
            if( i % 2 == 0){
                if( j % 2 == 0 && t[i][j] == 'F') count ++;
            }
            else{
                if( j % 2 == 1 && t[i][j] == 'F') count ++;
            }
        }
    }
    cout << count;
    return 0;
}