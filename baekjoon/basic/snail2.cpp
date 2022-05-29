#include <iostream>

using namespace std;

int main(){

	int a,b,v;
    int D;
	
	cin >> a >> b >> v;
	int c = a - b;
	v -= a;

    D = v/c;
    if(v % c != 0) D++;
    
    D++;
	cout << D;
}
