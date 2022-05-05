#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int c;
	long a,b;
	
	cin >> c;

	while(c){
		cin >> a >> b;
		long long p = pow(a,b);
		long x = p % 10;
		if( x  == 0) cout << "10" << endl;
		else cout << x << endl;
	}

}
