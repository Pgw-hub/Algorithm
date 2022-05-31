#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int N;
	string s;
	cin >> N >> s;

	int sum = 0;
	for(int i = 0; i < s.size(); i++){
		int a = s[i] - '0';
		sum += a;
	}

	cout << sum;


	return 0; 
}
