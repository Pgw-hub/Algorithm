#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string, int>& a, pair<string, int>& b){
	return a.second > b.second;
}

int main(){
	int N;
	map<string, int> m;
	map<string,int>::iterator iter;
	map<string, int> result_m;
	string name;
	cin >> N;

	while(N--){
		cin >> name;
		//name이 있는 지 확인
			//없으면 뒤에 추가 + 1
			//있으면 해당 key의 value + 1
		if((iter = m.find(name)) == m.end()){
			m.insert({name,1});
		}
		else{
			(iter -> second)++;
		}
	}

	vector<pair<string, int>> v(m.begin(),m.end());
	sort(v.begin(),v.end(),comp);

	//가장 많이 팔린 책만 사전순 정렬
	int max = v[0].second;
	for(int i = 0; i < v.size(); ++i){
		if(v[i].second == max){
			result_m.insert({v[i].first, v[i].second});
		}	
	}

	cout << result_m.begin() -> first;

	
	return 0;
}
