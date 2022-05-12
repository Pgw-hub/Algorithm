#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){

	ifstream fin("hw4_.data.txt");
	string line[20];
	vector <string> v = {"	A	B	C	D	E	F	G	H","A  	0	0	1	1	0	1	0	1","B	0	0	1	1	1  	0	0	0  ","C  	0	0	0	0	1  	0	0	1  ","D          	1 	0  	1	0	0	1	0	0","E	0	0	1	0	0	0	1  	0","F	1	0	1  	0	0 	0	0	1","G	0	0	0	1  	1	0	0	0","H	0	1	0	0	0	1	0	0"};
	vector < vector<char> > vc;
	char adj_arr[20][20] = {};
	// string s

	//file open
	// if(!fin.is_open()){
	// 	cout << "fail to open file";
	// 	exit(-1);
	// }
	// //file reading
	int i = 0;
	// while(!fin.eof()){
	// 	getline(fin,line[i]); // string header에 있는 getline
	// 	i++;
	// }

	// //cout << "i is = " << i << endl;


	// //put line into vector<string>
    // for(int j = 0; j < i; j++){
    //     cout <<"line ["<< j << "] : "<< line[j] << endl;
    //     v.push_back(line[j]);
    // }

	//cout << "vector size is = " << v.size() << endl;


    //put 0 , 1 into adj_array
    int x = 0;
    int y = 0;
	for(i = 1; i < v.size(); i++){
        y = 0;
		for(int j = 0; j <= v[i].size(); j++){
			if(v[i][j] == '1' || v[i][j] == '0'){
				adj_arr[x][y] = v[i][j];
                y++;
			}
		}
        x++;
	}

    //print adj_array
	int size = x; 
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << adj_arr[i][j] << " ";
		}
		cout << endl;
	}
    
	fin.close();
	return 0;
}
