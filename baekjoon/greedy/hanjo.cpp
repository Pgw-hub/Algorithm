#include <iostream>

using namespace std;

int main(){

	int best = 0;
	int cand;
	int count = 0;
	int tmp;
	int N;

	cin >> N;

	cin >> cand;

	for(int i = 1; i < N; i++){
		cin >> tmp;

		if( cand > tmp){
			count ++;
			if(count > best) best = count;
		}
		else{
			if(count > best) best = count;
			count = 0;
			cand = tmp;
		}
	}

	cout << best;

	return 0;
}
