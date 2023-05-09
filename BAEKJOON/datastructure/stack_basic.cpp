#include <iostream>
#include <memory.h>

using namespace std;

int front = 0;
int cursor = 0;
int stack[10001];

int main(){

	memset(stack,0,sizeof(stack));
	
	int lineNum;
	int num;
	string command;

	cin >> lineNum;

	while(lineNum--){

		cin >> command;
		if(command == "quit") break;
		else{
			if(command == "push"){			
				cin >> num;
				stack[cursor++] = num;
			}
			else if(command == "pop"){
				if(cursor > 0){
					cout << stack[cursor - 1] << endl;
					stack[cursor - 1] = 0;
					cursor--;
				}
				else cout << -1 << endl;
			}
			else if(command == "size"){
				cout << cursor << endl;				
			}
			else if(command == "empty"){
				if(cursor == 0) cout << 1 << endl;
				else cout << 0 << endl;
			}
			else if(command == "top"){
				if(cursor > 0)cout << stack[cursor - 1] << endl;
				else cout << -1 << endl;
			}
			else{
				cout << "typo" << endl;
			}
		}
	}

	return 0;

}
