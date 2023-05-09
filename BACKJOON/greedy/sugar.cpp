#include <iostream>

using namespace std;

int main(){

	int N;
	int count = 0;

	cin >> N;

	//5로 나눠떨어지면 바로 그 값을 출력
	if( N % 5 == 0){
		count += (N / 5);
		cout << count;
		return 0;
	}
	else{
		count = N / 5;
		N = N % 5;
	}
	
	while( N > 0){
		//떨어지지 않으면 3으로 나눠보고 나눠지면 3나누기의 해 더 출력
		//3으로 나눠지지않으면 5을 다시 빼고 count --하기
		if( N % 3 == 0){
			count += (N / 3);
			cout << count;
			break;
		}
		else{
			if(count!=0){
				N += 5;
				count --;
			}
			else{
				cout << -1;
				break;
			}
		}
	}
	return 0;
}
