#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

#define Max 100001
#define Start 1

using namespace std;

int N;
vector<int> Map[Max];
bool Visited[Max];
int Parent[Max];

void BFS(int node){
	queue<int> q;

	Visited[node] = 1;
	q.push(node);

	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int i = 1; i <= Map[curr].size(); ++i){
			int next = Map[curr][i - 1];
			if(!Visited[next]){
				Visited[next] = 1;
				q.push(next);
				Parent[next] = curr;
			}
		}
	}
}

int main(){
	memset(Visited,0,sizeof(Visited));
	memset(Parent,0,sizeof(Parent));

	cin >> N;

	for(int i = 0; i < N - 1; ++i){
		int f,t;
		cin >> f >> t;
		//undirected
		Map[f].push_back(t);
		Map[t].push_back(f);
	}

	BFS(Start);

	for(int i = 2; i <= N; ++i){
		printf("%d\n",Parent[i]);
	}	

	return 0;
}
