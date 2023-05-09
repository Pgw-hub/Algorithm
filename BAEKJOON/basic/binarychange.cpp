#include <iostream>
#include <stack>

using namespace std;

void modifier(char element,int i);

int main(){
	string num;
	cin >> num;
	for(int i=0; i < num.size(); i++){
		modifier(num[i],i);
	}
}

void modifier(char element, int i){
	stack<int> s;
	int a = element - '0';
	int temp = a;

	while(a){
		s.push(a % 2);
		a = a / 2;
	}

	if(i != 0){
		if(temp < 4) s.push(0);
		if(temp < 2) s.push(0); 
		if(temp == 0) s.push(0);
	}
	else{
		if(temp == 0){
			cout << '0';
			return;
		}
	}
	
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
}
