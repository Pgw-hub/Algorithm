#include <iostream>
#include <string>

using namespace std;



int main(){

	string form;

	cin >> form;

	string tmp = "";
	int answer = 0;
	int flag = false;

	for(int j = 0; j <= form.size(); j++){
		//+, - , \0일떄 answer에 정수화 후 값을 더해준다.
		if(form[j] == '+' || form[j] == '-' || form[j] == '\0'){

			if(flag == false) answer += stoi(tmp);
			else answer -= stoi(tmp);
			tmp = "";

			if(form[j] == '-'){
				flag = true;	
			}
		}
		else{
			tmp += form[j];
		}
	}

cout << answer;
return 0;
}
