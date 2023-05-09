#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){

	ifstream fin("hw4_.data.txt");
	string line[20];
	vector <string> v;
	vector < vector<char> > vc;
	char arr[20][20] = {};
	// string s

	//file open
	if(!fin.is_open()){
		cout << "fail to open file";
		exit(-1);
	}
	//file reading
	int i = 0;
	while(!fin.eof()){
		getline(fin,line[i]); // string header에 있는 getline
		i++;
	}

	//cout << "i is = " << i << endl;


	//put line into vector<string>
    for(int j = 0; j < i; j++){
        cout <<"line ["<< j << "] : "<< line[j] << endl;
        v.push_back(line[j]);
    }

	//cout << "vector size is = " << v.size() << endl;


	int k = 0;
    int x = 0;
    int y = 0;
	//put 0 , 1 into vector< vector<char> >
	for(i = 0; i < v.size(); i++){
		k = 0;
        y = 0;
		for(int j = 0; j < v[i].size(); j++){
			if(v[i][j] == '1' || v[i][j] == '0'){
				cout << "find!" << v[i][j] << " ";
				//vc[x].push_back(v[i][j]);//여기에서만 오류?..
				arr[x][y] = v[i][j];
                y++;
				k++;
			}
		}
        x++;
		cout << endl;
	}

	i = i-1;
	cout << "i = " << i << "k = " << k << endl;
	int N = i;
	int M = k;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
    
	fin.close();
	return 0;
}
