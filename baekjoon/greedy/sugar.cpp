#include <iostream>

using namespace std;

int main(){

	int N;
	int count = 0;

	cin >> N;
	
	while( N < 0){
		if(N % 5 == 0 ){
			count += N / 5;
			N = N % 5;
		}

	}

	return 0;
}
