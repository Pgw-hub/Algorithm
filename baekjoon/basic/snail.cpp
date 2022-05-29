#include <iostream>

using namespace std;

int main(){

	int a,b,v;
	int D = 0;
	
	cin >> a >> b >> v;

	int c = a - b;
	while(v){
		v -= c;
		if(v - a <= 0){
			D += 2;
			break;
		}
		else D++;
	}
	cout << D;
}
