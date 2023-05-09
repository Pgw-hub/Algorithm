#include <iostream>
#include <list>

using namespace std;

int main(){

	list<int> b;

	for(int i = 0; i < 5; i++){
		b.push_back(i);
	} 

	cout << "size of list = " << b.size() << endl;

	
		cout << b.front() << endl;
		b.pop_front();
		cout << b.front() << endl;
		b.pop_front();
		cout << b.front() << endl;
		b.pop_front();
		cout << b.front() << endl;
		b.pop_front();
		cout << b.front() << endl;
		b.pop_front();

	cout << "size of list = " << b.size() << endl;


}


