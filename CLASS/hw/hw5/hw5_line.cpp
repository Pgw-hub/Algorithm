//lecture : slide chapter 24,5
//blog : 1) https://www.delftstack.com/ko/howto/cpp/pass-vector-by-reference-in-cpp/
//		 2) https://blog.naver.com/ndb796/221234427842
//       3) https://blog.naver.com/ndb796/221234424646
//book : no book
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int> > a[30];
int d[30];

void dijkstra(int start);
void floyd(vector<vector <int> > &d, int number);
void printResult(int source,int number, int d[], vector<string> &region);
void printResult(vector<vector<int> > &a,int number, vector<string> &region);
void printRegionTitle(vector<string> &region);

int main(void){
    string line[30];
    int INF = 10000000;
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
    int number = i - 2;

    //vector에 각각의 요소 넣기.
    vector <vector<string> > vec;
    vector <string> region;
    vec.push_back({"0"});//for index matching
    for(int j = 1; j <= number; j++){
        vector <string> v;
        istringstream ss(line[j]);
        string stringBuffer;
        while(getline(ss,stringBuffer, '\t')){
            v.push_back(stringBuffer);
        }
        //쓰레기값 지우기
        v.erase(remove(v.begin(), v.end(), ""), v.end());
        //각 v를 vec에 넣기
        vec.push_back(v);
        //save region name
        region.push_back(v[0]);
      }

    //convert string to int and make vector<int>
    int size = vec.size();
    vector< vector<int> > vec_int;
    vec_int.push_back({0});//for index matching
    for(int i = 1; i < size; i++){
        vector<int> v_int;
        v_int.push_back(0);//for index matching
        for(int j = 1; j < size; j++){
            //if INF then put INF(1000000)
            if(vec[i][j].find("INF") == 0){
                v_int.push_back(INF);    
            }
            //else convert the string num to int num
            else{
                v_int.push_back(stoi(vec[i][j]));
            }
        }
        vec_int.push_back(v_int);
    }

    //pair로 간선들의 정보를 vector<pair<int, int> > 에 저장하기.a[i] = (to, distance)
    for(int i = 1; i <= number; i++){
        for(int j = 1; j <= number; j++){
            if(vec_int[i][j] != 0 && vec_int[i][j] != INF){
                a[i].push_back(make_pair(j,vec_int[i][j]));
            }
        }
    }
	
    //dijkstra
    cout << "\nThe followings are shortest distances between cities with Dijkstra's algorithm" << endl;
    printRegionTitle(region);
    for(int node = 1; node <= number; node++){
        //initialize dist to 0
        for(int i = 1; i <= number; i++) d[i] = INF;
        dijkstra(node);
        printResult(node, number, d, region);
    }

    //floyd
    cout << "\nThe followings are shortest distances between cities with Floyd algorithm" << endl;
    printRegionTitle(region);
    floyd(vec_int, number);
    printResult(vec_int,number,region);

    return 0;
}

void floyd(vector<vector <int> > &d, int number){
    for(int k = 1; k <= number; k++){
        for(int i = 1; i <= number; i++){
            for(int j = 1; j <= number; j++){
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(start,0));
    //음수화 pq
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

void printResult(int source,int number, int d[], vector<string> &region){
    cout <<setw(15) << region[source - 1];
    for(int i = 1; i <= number; i++){
        cout << setw(15) << d[i];
    }
    cout << endl;
}

void printResult(vector<vector<int> > &a,int number, vector<string> &region){
    for(int i = 1; i <= number; i++){
        cout <<setw(15) << region[i - 1];
        for(int j = 1; j <= number; j++){
            cout << setw(15) << a[i][j];
        }
        cout << endl;
    }
}

void printRegionTitle(vector<string> &region){
     cout << "                 ";
    for(int i = 0; i < region.size(); i++){
        cout << setw(15) << region[i];
    }
    cout << endl;
}
