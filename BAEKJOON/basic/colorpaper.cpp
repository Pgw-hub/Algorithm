#include <iostream>

using namespace std;

int main(){

    int cnt;
    int area = 0;
    int map[101][101] = {0};
    
    cin >> cnt;

    while(cnt--){
        int x, y;
        cin >> x >> y;

        for( int i = x; i < x + 10; ++i){
            for( int j = y; j < y + 10; ++j){
                if(map[i][j] != 1){
                    map[i][j] = 1;
                    area ++;
                }
            }
        }
    }

    cout << area;

    return 0;
}