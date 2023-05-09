#include <iostream>
#include <memory.h>

using namespace std;

int front;
int cursor;
int queue[2000001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(queue,0,sizeof(queue));

	int lineNum;
	int num;
	string command;
	int size = 0;

	cin >> lineNum;

	while(lineNum--){
		size = cursor - front;

		cin >> command;

		if(command == "quit") break;
		else{
			if(command == "push"){
				cin >> num;
				queue[cursor++] = num;
			}
			else if(command == "pop"){
				if(size == 0) cout << -1 << "\n";
				else{
					cout << queue[front] << "\n";
					queue[front++] = 0;
				}
			}
			else if(command == "size"){
				cout << size << "\n";
			}
			else if(command == "empty"){
				if(size == 0) cout << 1 <<  "\n";
				else cout << 0 << "\n";
			}
			else if(command == "front"){
				if(size== 0) cout << -1 << "\n";
				else cout << queue[front] << "\n";
			}
			else if(command == "back"){
				if(size== 0) cout << -1 << "\n";
				else cout << queue[cursor - 1] << "\n";
			}
			else{
				cout << "typo" << "\n";
			}
		}
	}
	return 0;
}
