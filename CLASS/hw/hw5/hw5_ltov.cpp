#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    string line[10] = {
        "Busan  		0	108	INF	INF		INF	INF	106	110	INF	INF",
        "Daegu		108	0	152	359		211	INF	135	87	INF	189",
        "Daejeon		INF	152	0	INF		INF  	86	INF  	INF	161	INF",
        "Gangeung	INF	359  	INF	0		INF	INF	INF	237	INF	126",
        "Gwangju		INF	211	INF	INF		0	99	161  	INF	INF	INF",
        "Jeonju		INF	INF	86	INF		99 	0	INF	INF	255	INF",
        "Jinju		106	135	INF	INF  		161	INF	0	INF	INF	INF",
        "Pohang		110	87	INF	237		INF	INF	INF	0	INF	INF",
        "Seoul 		INF	INF	161	INF		INF	255	INF	INF	0	110",
        "Wonju		INF	189	INF	126		INF	INF	INF	INF	110	0"
    };


    //vector에 각각의 요소 넣기.
    vector <vector<string> > vec;
    vec.push_back({"0"});//for index matching
    for(int j = 0; j < 10; j++){
        vector <string> v;
        istringstream ss(line[j]);
        string stringBuffer;

        while(getline(ss,stringBuffer, '\t')){
            v.push_back(stringBuffer);
            cout << stringBuffer << " ";
        }
        v.erase(remove(v.begin(), v.end(), ""), v.end());
        cout << endl;
        vec.push_back(v);
        for(int k = 0; k < v.size(); k++){
            cout <<"in [" << k <<"] vector = "<< v[k] << endl;
        }
      }

       
      //두자리숫자 string을 int로 만들기, stoi
        //만약 INF이면 10000000짚어넣기.
        int size = vec.size();
        vector< vector<int> > vec_int;
        vec_int.push_back({0});//for index matching

        for(int i = 1; i < size; i++){
            vector<int> v_int;
            v_int.push_back(0);//for index matching
            for(int j = 1; j < size; j++){
                if(vec[i][j].find("INF") == 0){
                    v_int.push_back(1000000);    
                }
                else{
                    v_int.push_back(stoi(vec[i][j]));
                }
            }
            vec_int.push_back(v_int);
        }

        cout << "hi";

         



  
}
