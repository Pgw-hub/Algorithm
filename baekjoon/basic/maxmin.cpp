#include <iostream>

using namespace std;

int main(){
	int N;
	int a[1000000];
	int min;
	int max;

	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> a[i];
	}


	min = a[0];
	max = a[0];
	for(int i = 0; i < N; i++){
		if(min > a[i] ) min = a[i];
		if(max < a[i] ) max = a[i];
	}
	
	cout << min << " " << max;

return 0;
}
