#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 10;
int INF = 10000000;


vector<pair<int, int> > a[11];
int d[11];


void dijkstra(int start);




int main(){
    int data[11][11] = {
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,108,INF,INF,INF,INF,106,110,INF,INF},
        {0,108,0,152,359,211,INF,135,87,INF,189},
        {0,INF,152,0,INF,INF,86,INF,INF,161,INF},
        {0,INF,359,INF,0,INF,INF,INF,237,INF,126},
        {0,INF,211,INF,INF,0,99,161,INF,INF,INF},
        {0,INF,INF,86,INF,99,0,INF,	INF,255,INF},
        {0,106,135,INF,INF,161,INF,0,INF,INF,INF},
        {0,110,87,INF,237,INF,INF,INF,0,INF,INF},
        {0,INF,INF,161,INF,INF,255,INF,INF,0,110},
        {0,INF,189,INF,126,INF,INF,INF,INF,110,0},
    };

    //pair로 간선들의정로보를 vector에 저장하기
    for(int i = 1; i <= number; i++){
        for(int j = 1; j <= number; j++){
            if(data[i][j] != 0 && data[i][j] != INF){
                a[i].push_back(make_pair(j,data[i][j]));
            }
        }
    }
	
    for(int node = 1; node <= number; node++){
        //최소거리 초기화 
        for(int i = 1; i <= number; i++){
            d[i] = INF;
        }
        
        dijkstra(node);
        
        //출력
        
        for(int i = 1; i <= number; i++){
            printf("node [%d] : dist to %d = %d\n",node, i ,d[i]);
        }
        cout << endl;
    }
}











void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int,int> > pq;

	pq.push(make_pair(start,0));

	while(!pq.empty()){
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();

		if(d[current] < distance) continue;
		for(int i = 0; i < a[current].size(); i++){
			int next = a[current][i].first;
			int nextDistance = distance + a[current][i].second;

			if(nextDistance < d[next]){
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

