#include <iostream>
#include <memory.h>

#define Max 1001

using namespace std;

int Map[Max][Max];
int Visited[Max];
int T;
int count = 0;

void DFS(int node,int N){
	Visited[node] = 1;
	//cout << node << " ";
	::count++;

	for(int i = 1; i <= N; ++i){
		if(!Visited[i] && Map[node][i]){
			DFS(i,N);
		}
	}
}

int main(){

	cin >> T;

	while(T--){
		int N, M;
		int start;
		::count = 0;
		memset(Map,0,sizeof(Map));
		memset(Visited,0,sizeof(Visited));
		
		cin >> N >> M;

		for(int i = 0; i < M; i++){
			int f,k;
			cin >> f >> k;
			if(i == 0) start = f;
			Map[f][k] = Map[k][f] = 1;
		}
		DFS(start, N);

		cout << ::count - 1 << endl;
	}
}
