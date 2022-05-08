#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	string color[10] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
	int index[3] = {};
	string C[3];
	cin >> C[0] >> C[1] >> C[2];

	for(int i = 0; i < 3; i++){
		for(int k = 0; k < 10; k++){
			 if(color[k].compare(C[i]) == 0){
				index[i] = k; 
				break;
			 }
		}
	}

	long answer = (index[0]*10 + index[1]) * pow(10,index[2]);
	cout << answer;


return 0;

}
