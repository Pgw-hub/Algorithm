#include <iostream>
#include <memory.h>
#include <vector>
#include <utility>

//위아래좌우 여백 1씩.
#define Max 53

using namespace std;

int T;
int M,N,K;
int Map[Max][Max];
int Visited[Max][Max];
//탐색하는 본인의 동서남북좌표를 확인하는데, 만약 방문하지 않았던 친구라면 방문해서 다시 동서남북좌표확인.

void WhiteWarm(int x, int y){
	Visited[x][y] = 1;

	if(!Visited[x - 1][y] && Map[x - 1][y]) WhiteWarm(x - 1,y);//left
	if(!Visited[x][y - 1] && Map[x][y - 1]) WhiteWarm(x,y - 1);//bottom
	if(!Visited[x + 1][y] && Map[x + 1][y]) WhiteWarm(x + 1,y);//right
	if(!Visited[x][y + 1] && Map[x][y + 1]) WhiteWarm(x,y + 1);//top
}

int main(){

	cin >> T;

	while(T--){
		//초기화
		int count = 0;
		memset(Map,0,sizeof(Map));
		memset(Visited, 0, sizeof(Visited));
		vector< pair<int,int> > v;

		//값 받기
		cin >> M >> N >> K;
		for(int i = 0; i < K; ++i){
			int f,k;
			cin >> f >> k;
			f = f + 1;//여백
			k = k + 1;
			v.push_back(make_pair(f,k));
			Map[f][k] = 1;
		}

		//흰배추
		for(int i = 0; i < v.size(); ++i){
			if(!Visited[v[i].first][v[i].second]){
				count ++;
				WhiteWarm(v[i].first,v[i].second);
			}
		}
		cout << count << endl;
	}
	
}
