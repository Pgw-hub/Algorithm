#include <iostream>
#include <vector>
using namespace std;

int main(){
	int num;
	vector<char> v;

	cin >> num;
	
	while(num != 0){
		num = num / 2;
		int check = num % 2;	
		if(check == 1) v.push_back('1');
		else v.push_back('0');
	}

	for(int i = v.size(); i >= 0; i--){
		cout << v[i];
	}

	


}
