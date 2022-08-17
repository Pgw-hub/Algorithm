#include <iostream>
#include <memory.h>

using namespace std;

#define MAX 101

int Map[MAX][MAX];
int Visited[MAX];
int N, L;
int count = 0;;

void DFS(int node){
	Visited[node] = true;
	//cout << node << " ";
	::count++;

	for(int i = 1; i <= N; ++i){
		if(!Visited[i] && Map[node][i]) DFS(i);
	}
}

int main(){

	cin >> N >> L;

	memset(Map,0,sizeof(Map));
	memset(Visited,0,sizeof(Visited));

	for(int i = 0; i < L; ++i){
		int f,t;
		cin >> f >> t;
		Map[f][t] = Map[t][f] = 1;
	}

	DFS(1);

	cout << ::count - 1;

	return 0;
}
