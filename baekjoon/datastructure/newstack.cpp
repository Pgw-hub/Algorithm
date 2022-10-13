#include <iostream>
#include <vector>

using namespace std;

int cursor;

int main(){
	vector<int> v;
	int num;

	cin >> num;

	for(int i = 0; i < num; i++){
		int tmp;
		cin >> v.push_back(tmp);
	}

	cout << v.size();

	//TODO : 전체입력 vector로 넣기.
	//TODO : vector의 사이즈 만큼 반복.
		//TODO : 현재 cursor 와 다음 숫자만큼의 차이만큼 + or -

	
	return 0;
}
