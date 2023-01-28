#include <iostream>

using namespace std;

int main(){
    int point = 0;
    int num[5];
    for(int i = 0; i < 5; ++i){
        cin >> num[i];
    }

    int answer = 1;
    while(1){
        //num을 다 나눠보기.
        for(int i = 0; i < 5; ++i){
            if(answer % num[i] == 0) point++;
        }

        //initialize
        if(point >= 3){
            cout << answer;
            break;
        }
        else{
            point = 0;
            answer++;
        }
    }
    return 0;
}