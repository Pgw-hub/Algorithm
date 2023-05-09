#include <iostream>
#include <memory.h>

using namespace std;

int main(){

	int mat1[101][101];
	int count = 2;
	int input, N, M;

	cin >> N >> M;

	memset(mat1,0,sizeof(mat1));

	while(count--){
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j){
				cin >> input;
				mat1[i][j] += input;
			}
		}
	}

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cout << mat1[i][j] << " ";
		}
		cout << endl;
	}
}
