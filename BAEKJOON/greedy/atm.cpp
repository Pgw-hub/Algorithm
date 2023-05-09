#include <iostream>
#include <queue>
using namespace std;

int main(){
	priority_queue<int> pq;
	int min = 0;
	int sum = 0;
	int N;
	int tmp;

	cin >> N;

	for(int i = 0 ; i < N; i++){
		cin >> tmp;
		pq.push(-tmp);
	}

	while(!pq.empty()){
		sum += -pq.top();
		pq.pop();
		min += sum;
	}

	cout << min;


}
