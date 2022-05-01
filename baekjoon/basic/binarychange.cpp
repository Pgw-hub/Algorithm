#include <iostream>
#include <stack>

using namespace std;

void modifier(char element);

int main(){
	string num;
	cin >> num;
	for(int i=0; i < num.size(); i++){
		modifier(num[i]);
	}
}

void modifier(char element){
	stack<int> s;
	int a = element - '0';

	while(a){
		s.push(a % 2);
		a = a / 2;
	}
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
}
