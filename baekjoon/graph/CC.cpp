#include <iostream>
#include <memory.h>

using namespace std;

#define Max 1001

int N,M;
int Map[Max][Max];
int Visited[Max];

void DFS(int node){
	Visited[node] = 1;

	for(int i = 1; i <= N; ++i){
		if(!Visited[i] && Map[node][i]) DFS(i);
	}
}

int main(){
	int count = 0;
	memset(Map,0,sizeof(Map));
	memset(Visited,0,sizeof(Visited));

	cin >> N >> M;

	for(int i = 0; i < M; ++i){
		int f,t;
		cin >> f >> t;
		Map[f][t] = Map[t][f] = 1;
	}
	
	for(int i = 1; i <= N; ++i){
		if(!Visited[i]){
			DFS(i);
			count++;
		}
	}
	cout << count;
	return 0;
}
