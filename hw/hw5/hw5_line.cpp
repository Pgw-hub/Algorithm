#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int number = 10;
int INF = 10000000;


vector<pair<int, int> > a[11];
int d[11];


void dijkstra(int start);
void printResult(int source, int d[], vector<string> region);


int main(){
    string line[30];
    ifstream fin("hw5_data.txt");
    //file open check
    if(!fin.is_open()){
        cout << "fail to open file";
        exit(-1);
    }
    //file reading
    int i = 0;
    while(!fin.eof()){
        getline(fin,line[i]);
        i++;
    }

    // cout << "----------------native line-----------------" << endl;
    
    // for(int j =0; j < i; j++){
    //     cout <<"line "<< j << " : "<< line[j] << endl;
    // }

    //vector에 각각의 요소 넣기.
    vector <vector<string> > vec;
    vector <string> region;
    vec.push_back({"0"});//for index matching
    for(int j = 1; j <= 10; j++){
        vector <string> v;
        istringstream ss(line[j]);
        string stringBuffer;

        while(getline(ss,stringBuffer, '\t')){
            v.push_back(stringBuffer);
            // cout << stringBuffer << " ";
        }
        v.erase(remove(v.begin(), v.end(), ""), v.end());
        // cout << endl;
        vec.push_back(v);
        region.push_back(v[0]);
        // for(int k = 0; k < v.size(); k++){
        //     cout <<"in [" << k <<"] vector = "<< v[k] << endl;
        // }
      }

      //두자리숫자 string을 int로 만들기, stoi
        //만약 INF이면 10000000짚어넣기.
        int size = vec.size();
        vector< vector<int> > vec_int;
        vec_int.push_back({0});//for index matching

        for(int i = 1; i < size; i++){
            vector<int> v_int;
            v_int.push_back(0);//for index matching
            for(int j = 1; j < size; j++){
                if(vec[i][j].find("INF") == 0){
                    v_int.push_back(INF);    
                }
                else{
                    v_int.push_back(stoi(vec[i][j]));
                }
            }
            vec_int.push_back(v_int);
        }

    //pair로 간선들의정로보를 vector에 저장하기
    for(int i = 1; i <= number; i++){
        for(int j = 1; j <= number; j++){
            if(vec_int[i][j] != 0 && vec_int[i][j] != INF){
                a[i].push_back(make_pair(j,vec_int[i][j]));
            }
        }
    }
	
    //지역출력
    cout << "                 ";
    for(int i = 0; i < region.size(); i++){
        // printf("%s ",region.c_str(i));
        // cout.width(10);
        // cout.fill();
        cout << setw(15) << region[i];
    }
    cout << endl;
    
    for(int node = 1; node <= number; node++){
        //최소거리 초기화 
        for(int i = 1; i <= number; i++) d[i] = INF;
        
        dijkstra(node);

        printResult(node, d, region);
        
        //for(int i = 1; i <= number; i++)  printf("node [%d] : dist to %d = %d\n",node, i ,d[i]);
       // cout << endl;
    }
}

void printResult(int source, int d[], vector<string> region){
    //    printf("node [%d] : dist to %d = %d\n",source, i ,d[i]);
    cout <<setw(15) << region[source - 1];
    for(int i = 1; i <= number; i++){
        cout << setw(15) << d[i];
    }
    cout << endl;
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

