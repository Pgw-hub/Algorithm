#include <iostream>

using namespace std;

int main(){
	int N;
	char star = '*';
	cin >> N;

	while(N--){
		for(int i = 0; i <= N; ++i){
			cout << star;
		}	
		cout << "\n";
	}
	return 0;
}
