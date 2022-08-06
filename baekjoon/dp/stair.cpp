#include <iostream>
#include <vector>

using namespace std;

int main(){


	//시작을 0에서 시작하면 될듯.
	int mem[301];
	vector<int> v;

	int N;
	
	cin >> N;
	
	v.push_back(0);
	while(N--){
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	mem[0] = 0;
	mem[1] = v[1];
	mem[2] = v[1] + v[2];
	//3번째 칸부터는 연속으로 3번밟을 수 없으니, 처음에 두칸뛰고 밟을지, 한칸밟고 생각하고 가야함.



	return 0;

}
