#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
	int s_time;
	int f_time;
} Meeting;

bool cmp(const Meeting &t1, const Meeting &t2){
    if(t1.f_time < t2.f_time){
        return true;
    }
    else if(t1.f_time == t2.f_time){
        return t1.s_time < t2.s_time;
    }
    else{
        return false;
    }
}

int Greedy(Meeting* m, int size){
	
	sort(m, m + size, cmp);

	int end = m[0].f_time;
	int count = 1;
	for(int i = 1; i < size; i++){
		if(m[i].s_time >= end){
			// cout << m[i].s_time << " " << m[i].f_time << endl;
			count ++;
			end = m[i].f_time;
		}
	}
	
	return count;
}


int main(){
	
	int N;
	Meeting m[100001];

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> m[i].s_time >> m[i].f_time;
	}

	cout <<  Greedy(m, N);



return 0;
}
