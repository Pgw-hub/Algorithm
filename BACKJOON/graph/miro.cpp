#include <iostream>
#include <memory.h>
#include <queue>
#include <utility>

using namespace std;

#define Max 102

int N,M;
int Map[Max][Max];
int Visited[Max][Max];
int Distance[Max][Max];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void Escape(int x, int y){
	queue< pair<int,int> > q;

	//put the initial value into the queue
	Visited[x][y] = 1;
	q.push(make_pair(x,y));

	while(!q.empty()){
		//get the top value
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		//detect four sides of each node. 
		for(int i = 0; i < 4; ++i){
			int next_a = a + dx[i];
			int next_b = b + dy[i];
			//if unvisited and existed
			if(!Visited[next_a][next_b] && Map[next_a][next_b]){
				//cout << "Visit : " << next_a << " , " << next_b << endl;
				Visited[next_a][next_b] = 1;
				//memorize distance
				Distance[next_a][next_b] = Distance[a][b] + 1;
				q.push(make_pair(next_a,next_b));
			}
		}
	}
}

int main(){

	memset(Map,0,sizeof(Map));
	memset(Distance,0,sizeof(Distance));
	memset(Visited,0,sizeof(Visited));

	cin >> N >> M;

	for(int i = 1; i <= N; ++i){
		string tmp;
		cin >> tmp;
		for(int j = 1; j <= M; ++j){
			Map[i][j] = tmp[j - 1] - '0';
		}
	}

	Distance[1][1] = 1;
	Escape(1,1);

	cout << Distance[N][M] << endl;
}
