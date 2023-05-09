#include <iostream>
#include <queue>

using namespace std;

int main(){
	int K, N;
	queue<int> q; 

	cin >> N >> K;

	for(int i = 1; i <= N; i++){
		q.push(i);	
	}
	
	cout <<"<";
	while(!q.empty()){
		for(int i = 1; i <= K; i++){
			//i == N then print & kill
			if( i == K){
				cout << q.front();
				if(q.size() != 1) cout << ", ";
				q.pop();
			}
			//else pushback & kill
			else{
				q.push(q.front());
				q.pop();
			}
		}
	}
	cout << ">";


	return 0;
}
