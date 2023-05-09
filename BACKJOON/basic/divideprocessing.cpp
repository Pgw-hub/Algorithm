#include <iostream>

using namespace std;

int main(){
	int c;
	int a,b;
	int answer;
	
	cin >> c;

	while(c--){
		cin >> a >> b;
		b = (b % 4) + 4;
		answer = a;
			for(int i = 1; i < b; i++){
				answer = (answer * a) % 10;
			}
		if(answer  == 0) cout << 10 << endl;
		else cout << answer << endl;
	}
}
