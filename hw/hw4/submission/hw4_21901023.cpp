//lecture : slid chapter 22
//blog : 1) https://www.tutorialspoint.com/cplusplus-program-to-find-transpose-of-a-matrix
//		 2) https://jhnyang.tistory.com/196
//book : no book

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void print_matrix(int size, char arr[20][20]);
void make_adjlist(int size, char arr[20][20]);

int main(){
	
	string line[20];
	vector <string> v;
	char adj_arr[20][20] = {};
	char tp_arr[20][20] = {};

	//file open
	ifstream fin("hw4_.data.txt");

	//file open check
	if(!fin.is_open()){
		cout << "fail to open file";
		exit(-1);
	}

	// //file reading
	int i = 0;
	while(!fin.eof()){
		getline(fin,line[i]); // string header에 있는 getline
		i++;
	}

	// //put line into vector<string>
    for(int j = 0; j < i; j++){
        // cout <<"line ["<< j << "] : "<< line[j] << endl;
        v.push_back(line[j]);
    }

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
	int size = x; 

    // //print adj_array
		// cout <<endl << "############adj matrix############" << endl;
		// print_matrix(size, adj_arr);

	//make adj_list
	cout << endl << "############adj list############" << endl;
	make_adjlist(size,adj_arr);

	//transpose
	//  tp_arr = transpose(size, adj_arr);
	for(int i = 0; i < size; ++i){
		for(int j=0; j < size; ++j) {
   			tp_arr[j][i] = adj_arr[i][j];
		}
	}

	// //print transpose_adj_array
		// cout <<endl << "############transpose adj matrix############" << endl;
		// print_matrix(size, tp_arr);

	//make transpose_adj_list
	cout << endl << "############ transpose adj list ############" << endl;
	make_adjlist(size,tp_arr);
	
	fin.close();
	return 0;
}

void print_matrix(int size, char arr[20][20]){
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void make_adjlist(int size, char arr[20][20]){
	char i_name[20] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};
	for(int i = 0; i < size; i++){
		char tmp;
		tmp = i;
		cout << i_name[i] << " -> ";
		for(int j = 0; j < size; j++){
			if(arr[i][j] == '1'){
				cout << i_name[j]  <<" -> ";
			}
			if(j == size - 1) cout << "nil";
		}
		cout << endl;
	}
}