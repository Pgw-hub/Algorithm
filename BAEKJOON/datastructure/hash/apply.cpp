#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string>& a, const pair<int, string>& b){
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    unordered_map<string , int>  hash;
    
    int K, L;
    string student_number;
    int order = 1;

    cin >> K >> L;

    while(L--){
        cin >> student_number;
        hash[student_number] = order++;
    }

    vector<pair<int, string>> v;
	for (auto& i : hash){
		v.push_back(make_pair(i.second, i.first));
    }

    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < min(K, static_cast<int>(v.size())); ++i){
        cout << v[i].second << "\n";
    }

    return 0;
}