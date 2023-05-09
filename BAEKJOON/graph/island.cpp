#include <iostream>
#include <memory.h>

using namespace std;

#define Max 51

int h,w;
int Map[Max][Max];
int Visited[Max][Max];
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0};

void DFS(int x, int y){
	for(int i = 0; i < 8; ++i){
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if(next_x < 0 || next_y < 0 || next_x >= w || next_y >= h) continue;
		if(!Visited[next_x][next_y] && Map[next_x][next_y]){
			Visited[next_x][next_y] = 1;
			DFS(next_x,next_y);
		}
	}
}

int main(){
	

	while(1){
		int count = 0;
		memset(Visited,0,sizeof(Visited));
		memset(Map,0,sizeof(Map));

		cin >> w >> h;
		if(h == 0  && w == 0 ) break;
		
		//make map
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				cin >> Map[i][j];
			}
		}
	
		//travel
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				if(!Visited[i][j] && Map[i][j]){
					Visited[i][j] = 1;
					DFS(i,j);
					count ++;
				}
			}
		}

		cout << count << endl;
		
	}
	return 0; 
}
