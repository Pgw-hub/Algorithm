#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	ifstream fin("hw4_.data.txt");
	char line[100];

	while(fin.getline(line, sizeof(line)))
		cout << line << endl;
	
	fin.close();
	return 0;
}
