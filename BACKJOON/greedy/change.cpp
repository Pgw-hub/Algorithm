#include <iostream>

using namespace std;

int main(){
	int pay;
	int change;
	int count = 0;
	int b[6] = {500,100,50,10,5,1};

	cin >> pay;

	change = 1000 - pay;

	//change가 0 이 될때까지 반복함.
	//bill type =  500, 100, 50, 5 , 1
	int i = 0;
	while(change != 0){
		count += change / b[i];
		change = change % b[i];
		i++;
	}
	cout << count;
	return 0;
}
