// 섬의 개수(DFS)
// 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map[50][50],visit[50][50];
int dx[8]={1,1,0,-1,-1,-1,0,1},dy[8]={0,1,1,1,0,-1,-1,-1}; //이동할 좌표값들
int w,h;
void dfs(int y,int x){
    for(int i=0;i<8;i++){
        int nextX=x+dx[i];
        int nextY=y+dy[i];
        if(nextX<0||nextY<0||nextX>=w||nextY>=h)continue; //범위를 벗어나면 무시
        if(!visit[nextY][nextX]&&map[nextY][nextX]){ //이동할 좌표가 방문하지 않은 땅이면 재귀호출
            visit[nextY][nextX]=1;
            dfs(nextY,nextX);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);

    while(1){
        int cnt=0;
        cin>>w>>h;
        if(!w&&!h)break; //0,0을 입력하면 중지

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>map[i][j];
            }
        }
        
        for(int i=0;i<h;i++){ //브루트포스식으로 맵을 탐색하며 방문하지 않은 땅을 찾으면 알고리즘을 수행
            for(int j=0;j<w;j++){
                if(!visit[i][j]&&map[i][j]){
                    visit[i][j]=1;
                    dfs(i,j);
                    cnt++; //알고리즘을 수행했으면 그 땅은 모두 방문했을 것이므로 카운트를 하나 올려준다
                }
            }
        }
        cout<<cnt<<"\n";
        memset(visit,0,sizeof(visit)); //map은 덮어써도 문제가 없을 것이라 판단하여 visit만 초기화해준다피 
    }
}
