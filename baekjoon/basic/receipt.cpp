#include <iostream>

using namespace std;

int main(){
	int bill;
	int N;
	int sum = 0;
	cin >> bill;
	cin >> N;
	for(int i = 0; i < N; ++i){
		int a, b;
		cin >> a >> b;
		sum += ( a * b);
	}

	if( sum == bill) cout << "Yes";
	else cout << "No";
}
