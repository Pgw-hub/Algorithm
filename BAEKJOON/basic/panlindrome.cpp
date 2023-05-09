#include <iostream>
#include <cstring>

using namespace std;


bool panlindrome(string str){

	int size = str.size();
	int last = str.size() - 1;
	int comp_num = str.size() / 2;

	for(int i = 0; i < comp_num; i++){
		if(str[i] != str[last]) return false;
		last --;
	}

	return true;
}

int main(){
	string num;

    while(1){
        cin >> num;
        if( num == "0") return 0;
    	bool signal = panlindrome(num);
	    if(signal == 1) cout << "yes" << endl;
	    else cout << "no" << endl;
    }
	return 0;
}
