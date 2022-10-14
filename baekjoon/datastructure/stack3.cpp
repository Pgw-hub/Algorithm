#include <iostream>

using namespace std;

int stack[100001];
char output[300001];
int nodecnt = 0;

int main(){

ios_base::sync_with_stdio(false); //ios(input ouput base)
        cin.tie(0);
	int N;

	cin >> N;

	int key = 0;

	int out_num = 0;

	for(register int i = 0; i < N; i++){

		int input;
		
		cin >> input;
	
		while(key < input){ // input값과 같을때까지 계속해서 input해줌.

			key++;
			stack[nodecnt++] = key; //stack에는 오름차순으로 계속 key를 넣어줌. key의 상태가 계속최대값을 유지할 수 있도록.
			output[out_num++] = '+';

		}

		if(stack[nodecnt - 1] == input){ // 내려왔을때 아니면 바로 안되는 거임.
			nodecnt—-;
			output[out_num++] = '-';
		}
		else{
			out_num = -1;
			break;
		}

	}

	if(out_num == -1){
		cout << "NO\n";
		return 0;
	}

	for(register int i = 0; i < out_num; i++){

		cout << output[i] << '\n';

	}


	return 0;

}