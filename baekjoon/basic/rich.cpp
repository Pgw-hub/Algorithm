#include <iostream>

using namespace std;

int main(){

	unsigned long int n;
	unsigned long int m;

	cin >> n >> m;

	int a  = n / m;
	int leftover = n % m;

	cout << a << endl << leftover << endl;


return 0;
}
