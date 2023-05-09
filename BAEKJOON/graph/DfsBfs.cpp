#include <iostream>

using namespace std;

#define MAX_N 10
int N,E;
int Graph[MAX_N][MAX_N];
int Visited[MAX_N];

void dfs(int node){
	Visited[node] = true;
	cout << node << ' ';

	for(int next = 0; next < N; ++next){
		if(!Visited[next] && Graph[node][next]) dfs(next);
	}
}

int main(){
	cin >> N >> E;
	memset(Visited, 0, sizeof(Visited));
	memset(Graph, 0, sizeof(Graph));

	for(int i = 0; i < E; ++i){
		int u, v;

		cin >> u >> v;
		Graph[u][v] = Graph[v][u] = 1;
	}
	dfs(0);
	return 0;
}
