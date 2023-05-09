#include <iostream>

using namespace std;

int main(){

    int four = 0;
    int three = 0;
    int two = 0;
    int one = 0;
    int onethreetaxi = 0;

    int test[8] = {1,2,4,3,3};

    for(int i = 0; i < 5; ++i){
       if(test[i] == 1) one++;
        else if(test[i] == 2) two++;
        else if(test[i] == 3) three++;
        else four++;
    }

    //3에게 1을 분배
    int three_num = three;
    for(int i = 0; i < three_num; ++i){
        three --;
        one --;
        onethreetaxi ++;
        if(one == 0 || three == 0) break;
    }
    //남은 three의 갯수 확인해줘야함.

    //2와 1은 더해서 4로 나눈 몫이 답임.
    int extra_taxi = 0;
    int oneplustwo = one + (two * 2);
    int onetwotaxi = oneplustwo / 4;
    int extra_member = oneplustwo - (onetwotaxi * 4);
    if(extra_member > 0){
        extra_taxi = 1;
    }

    int total = four + onethreetaxi + onetwotaxi + three + extra_taxi;

    cout << total;
}