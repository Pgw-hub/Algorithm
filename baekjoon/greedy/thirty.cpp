#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool comp(char a, char b){
	return a > b;
}


int main(){
	string num;

	cin >> num;

	bool first_c = false;
	bool second_c = false;
	int sum = 0;

	//first condition_check zero
	int i;
	for( i = 0; i < num.size(); i++){
		if(num[i] == '0') first_c = true;
		sum += ( num[i] - '0');
	}
	
	//second condition_check the summation of all digits
	if( sum % 3 == 0) second_c = true;	

	if(first_c == true && second_c == true){
		sort(num.begin(), num.end(),comp);
		cout << num << endl;
	}
	else{
		cout << "-1" << endl;
	}

	return 0;
}


