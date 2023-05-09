#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j){
    return j < i;
}

int main(){

    vector<int> A, B;
    int answer = 0;
    // vector< vector<int> > check_sheet;
    bool answer_sheet[100001] = {};

    int N = 4;

    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        A.push_back(tmp);        
    }

    for(int i = 0; i < N; ++i){
        int tmp;
        cin >> tmp;
        B.push_back(tmp);
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end(), compare);


    int max_index = -1;
    for(int i = 0; i < B.size(); ++i){
        for(int j = 0; j < A.size(); ++j){
            if(B[i] > A[j]) {
                max_index = j;
            }
            else break;
        }
        answer_sheet[max_index] = true;
        max_index = -1;
    }

    for(int i = 0; i < A.size(); ++i){
        if(answer_sheet[i] == true) answer++;
    }

    cout << answer;

    return 0;
}