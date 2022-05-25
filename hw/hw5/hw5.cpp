#include <iostream>
#include <fstream>

using namespace std;

int main(){

    string line[30];
    
    ifstream fin("hw5_data.txt");

    //file open check
    if(!fin.is_open()){
        cout << "fail to open file";
        exit(-1);
    }

    //file reading
    int i = 0;
    while(!fin.eof()){
        getline(fin,line[i]);
        i++;
    }

    for(int j =0; j < i; j++){
        cout <<"line "<< j << " : "<< line[j] << endl;
    }

}