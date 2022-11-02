#include <iostream>
#include <queue>

using namespace std;

int main(){

	queue<int> q;
	int N,K;

	cin >> N >> K;

	for(int i = 1; i <= N; ++i){
		q.push(i);
	}

	cout << "<";
	while(!q.empty()){
		for(int i = 1; i <= K; ++i){
			if(i == K){
				//print & pop()
				cout << q.front();
				if(q.size() != 1) cout << ", ";
				q.pop();
			}
			else{
				//push back()
				q.push(q.front());
				q.pop(); 
			}
		}
	}
	cout << ">";

	return 0;
}
