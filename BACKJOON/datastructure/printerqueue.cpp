#include <iostream>
#include <queue>

using namespace std;


int main(){

    int count;
    int index_answer;
    int imp_answer;

    cin >> count;

    while(count--){
        queue<int> order;
        queue<int> imp;
        priority_queue<int> imp_ref;
        int N, M;

        cin >> N >> M;
        for(int i = 1; i <= N; ++i){
            int tmp;
            cin >> tmp;

            order.push(i);
            imp.push(tmp);
            imp_ref.push(tmp);

            if(i == M + 1){//make answer value
                index_answer = i;
                imp_answer = tmp;
            }
        }

        int bunjjae = 1;
        //till answer comes out
        while(!(index_answer == order.front() && imp_answer == imp.front() && imp.front() == imp_ref.top())){
            //violate the imp_order
            if(imp.front() != imp_ref.top()){
                order.push(order.front());
                order.pop();
                imp.push(imp.front());
                imp.pop();
            }
            //ok with imp_order -> print
            else{
                order.pop();
                imp.pop();
                imp_ref.pop();
                bunjjae++;
            }
        }
        cout << bunjjae << endl;
    }
    return 0;
}