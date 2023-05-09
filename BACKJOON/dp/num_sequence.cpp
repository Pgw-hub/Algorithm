#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (){

	int N;
	int tmp;
	int mem[1001] = {0};
	int ans = 0;
	vector<int> v;

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> tmp;
		v.push_back(tmp);
	}

	//핵심포인트 : 만약 뒤에 수가 앞에 수보다 크다면, 앞에 수까지의 가장 긴 수열에 해당하는 숫자들은 모두 해당 수보다 작은 수들로 이루어져있을테니, 거기에 +1을 해준 수가 뒤의 수의 mem값이 된다.
	for(int i = 0; i < N; i++){
		mem[i] = 1;
		for(int j = 0; j < i; j++){
			if(v[i] > v[j]){
				//작은 값을 만나지만, 굳이 바꿀 필요없는 작은값을 만날 수도있기 때문에 max를 해줌.
				mem[i] = max(mem[i],mem[j] + 1);
			}
		}
		ans = max(ans, mem[i]);
	}

	cout << ans;

	return 0;
}
