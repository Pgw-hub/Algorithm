#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){


	//시작을 0에서 시작하면 될듯.
	int mem[301];
	vector<int> v;

	int N;
	
	cin >> N;

	int size = N;
	
	v.push_back(0);
	while(N--){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}


	mem[0] = 0;
	mem[1] = v[1];
	mem[2] = v[1] + v[2];
<<<<<<< HEAD
	//도착지를 기준으로 두칸전 vs 세칸전의 max + 한칸전을 비교.
	for(int i = 3; i <= size; i++){
		mem[i] = max(mem[i-2], mem[i-3] + v[i-1]) + v[i];
=======
	//3번째 칸부터는 연속으로 3번밟을 수 없으니, 처음에 두칸뛰고 밟을지, 한칸밟고 생각하고 가야함.

	for(int i = 3; i <= size; i++){
		mem[i] = max(mem[i-2], mem[i-1]) + v[i];
>>>>>>> 4163fbf (change directory & start/dp/ sequence.cpp)
	}

	cout << mem[size];

	return 0;

}
