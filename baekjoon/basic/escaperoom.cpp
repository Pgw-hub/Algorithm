#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int x,y,w,h;

	cin >> x >> y >> w >> h;

	cout << min({x,y,h-y,w-x});

	return 0;
}
