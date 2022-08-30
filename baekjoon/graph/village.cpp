#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>

using namespace std;

#define Max 26

int Map[Max][Max];
int Visited[Max][Max];
int N;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int count = 0;
int v[25 * 13];//간격을 두고 모든 칸에 채워질 경우.

void BFS(int x, int y){
	Visited[x][y] = 1;
	queue< pair<int,int> > que;
	
	que.push(make_pair(x,y));

	while(!que.empty()){
		v[::count]++;
		int curr_x = que.front().first;
		int curr_y = que.front().second;
		que.pop();
		
		for(int i = 0; i < 4; ++i){
			int next_x = curr_x + dx[i];
			int next_y = curr_y + dy[i];
			if(next_x < 0 || next_y < 0 || next_x >=N || next_y >= N) continue;
			if(!Visited[next_x][next_y] && Map[next_x][next_y]){
				que.push(make_pair(next_x,next_y));
				Visited[next_x][next_y] = 1;
			}
		}
	}
}


int main(){
	priority_queue<int> q;
	memset(v,0,sizeof(v));

	cin >> N;

	for(int i = 0; i < N; ++i){
				for(int j = 0; j < N; ++j){
			char tmp;
			cin >> tmp;
			Map[i][j] = tmp - '0';		
		}
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(!Visited[i][j] && Map[i][j]){
				::count ++;
				BFS(i,j);
			}
		}
	}

	cout << ::count << endl;
	for(int i = 1; i <= ::count; i++){
		q.push( -v[i] );		
	}

	while(!q.empty()){
		cout << -q.top() << endl;
		q.pop();
	}
	

}
