#include <iostream>

using namespace std;

int main(){

	int m[12] = {0};
	int N;
	int a;

	m[1] = 1;
	m[2] = 2;
	m[3] = 4;

	cin >> a;

	while(a--){
		cin >> N;
		for(int i = 4; i <=N; i++){
			m[i] = m[i-1] + m[i - 2] + m[i - 3];
		}
		cout << m[N] << endl; 
	}

	return 0;
}
