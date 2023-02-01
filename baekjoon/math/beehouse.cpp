#include <iostream>

using namespace std;

int main(){

	int num;
	int i = 1;
	cin >> num;
	
	int count = 1;
	while(num > i){
		i += (count * 6);
		count++;
	}
	cout << count;
	return 0;
}
