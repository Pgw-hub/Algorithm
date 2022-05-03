#include <iostream>
#include <string>

using namespace std;

int main(){
	long N,F;
	long c;
	string s;

	cin >> N >> F;

	c = (N/100)*100;

	for(int i = c; i < c + 100; i++){
		if(i % F == 0){
			s = to_string(i);
			break;
		}
	}

	for(int i = s.size() - 2; i < s.size(); i++){
		cout << s[i];
	} 

	return 0;
}
