#include <iostream>

using namespace std;

int T(int N, int db[]);

int main(){

	int N;
    int db[1000]={};

	cin >> N;
    cout <<  T(N,db);   
    return 0;
}

int T(int N, int db[]){

	if( N == 1 ) return 1;
	else if( N == 2) return 2;
    if(db[N] != 0 ) return db[N];
	return db[N] = (T(N-1,db) + T(N-2,db)) % 10007;
}
