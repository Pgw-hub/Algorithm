#include <iostream>
#include <queue>

using namespace std;

int main(){

	priority_queue<pair<char, int> > pq;

	pq.emplace('A', 5);
	pq.emplace('A', 10);
    pq.emplace('A', 15);
    pq.emplace('B', 15);

	cout << pq.size() << endl;

	while(!pq.empty()){
		cout << pq.top().first << pq.top().second << endl;
		pq.pop();
	}

}
