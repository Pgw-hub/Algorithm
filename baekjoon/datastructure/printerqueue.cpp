#include <iostream>
#include <queue>

using namespace std;


int main(){

    int count;
    int index_answer;
    int imp_answer;

    cin >> count;

    while(count--){
        int imp_ref[10] = {};
        int cursor = 9;
        queue<int> order;
        queue<int> imp;
        int N, M;

        cin >> N >> M;
        for(int i = 1; i <= N; ++i){
            int tmp;
            cin >> tmp;

            order.push(i);
            imp.push(tmp);
            imp_ref[tmp]++;

            if(i == M + 1){
                index_answer = i;
                imp_answer = tmp;
            }
        }

        //initialize cursor
        for(int i = 9; i > 0; --i){
            if(imp_ref[i] == 0) cursor--;
            else break;
        }

       //imp_ref에서 가장 오른쪽에 있는 친구가 현재 imp의 front인지 확인.
       //imp_ref가 0이면 넘기기.
       //매번 front가 index_answer 인지, imp_answer인지 확인.
        int bunjjae = 1;
        while(!(index_answer == order.front() && imp_answer == imp.front() && imp.front() == cursor)){
            //만약 imp.front()가 Imp_ref의 가장 오른쪽에 있는 친구가 같지 않으면 order front와 imp front를 뒤로 보냄, bunjjae ++;
            //같으면 imp_ref의 0이 아닌 가장 오른쪽 수를 하난 줄임.
            if(imp_ref[cursor] == 0){
                cursor--;
            }
            else{
                if(imp.front() != cursor){
                    order.push(order.front());
                    order.pop();
                    imp.push(imp.front());
                    imp.pop();
                }
                else{
                    order.pop();
                    imp.pop();
                    imp_ref[cursor]--;
                    bunjjae++;
                }
            }
        }
        cout << bunjjae;
    }
    return 0;
}