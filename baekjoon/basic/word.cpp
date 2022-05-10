#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	string input;
	vector<char> temp;
	int c[32] = {0};
	
	cin >> input;

	for(int i = 0; i < input.size(); i++){
		input[i] = toupper(input[i]);
	}
	
	c[0] = 1;
	temp.push_back(input[0]);
	int flag = 0;

	for(int i = 1; i < input.size(); i++){
		flag = 0;
		for(int j = 0; j < temp.size(); j++){
			if(temp[j] == input[i]){//한번 찾았던 거면,
				c[j]++;
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			temp.push_back(input[i]);
			c[temp.size() -1] = 1;
		}
	}

	int max = c[0];
	int max_i;
	int size = sizeof(c)/sizeof(c[0]);
	for(int i = 0; i < size; i++){
		if(max <= c[i]){
			max = c[i];
			max_i = i;
		}
	}

	int m_count = 0;
	for(int i = 0; i < size; i++){
		if(max == c[i]){
			m_count++;
		}
	}
	
	if(m_count > 1){
		cout << "?";
	}
	else{
		cout << temp[max_i];
	}
	return 0;
}
