#include <iostream>
#include <queue>
#include <memory.h>
#include <unistd.h>

using namespace std;

#define MAX 1001

int N,M,V;
int Map[MAX][MAX];
int Visited[MAX];


void DFS(int node){
	//방문한 노드를 체크.
	Visited[node] = true;
	cout << node << " ";
	//해당 노드와 연결된 친구중에 방문하지 않았고, 가장 작은 순서대로 바로 리커젼으로 들어감.
	for(int i = 1; i <=N; i++){
		if( !Visited[i] && Map[node][i])
			DFS(i);
	}
}

void BFS(int node){
	queue<int> q;
	// 제일 시작 노드를 queue에 넣고 시작.
	q.push(node);
	Visited[node] = true;
	// queue가 빌때까지 반복.
	// 그다음에 해당 노드에 연결되어있고, 방문한적이 없는 친구들은 모두 queue에 넣기.
		//queue에 넣을떄 만약 queue안에 원래 있는 친구라면 넣지 말기
	while(!q.empty()){
		int v = q.front();
		q.pop();
		cout << v << " ";

		for(int i = 1; i <= N; ++i){
			if(!Visited[i] && Map[v][i]){
				q.push(i);
				Visited[i] = true;
			} //방문하지 않았고, 연결되어있다면 queue에 넣고, 넣은 건 방문했다고 표시
		}
	}
}

int main(){
	memset(Map,0,sizeof(Map));
	memset(Visited,0,sizeof(Visited));

	cin >> N >> M >> V;

	for(int i = 0; i < M; ++i){
		int f,t;
		cin >> f >> t;
		Map[f][t] = Map[t][f] = 1;
	}
	DFS(V);

	//초기화
	memset(Visited,0,sizeof(Visited));
	cout << endl;

	BFS(V);

	return 0;
}
