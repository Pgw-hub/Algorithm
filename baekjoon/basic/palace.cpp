#include <iostream>

using namespace std;

int main(){
	int N, M;
	bool row_check = false;
	bool column_check = false;
	int empty_row = 0;
	int empty_col = 0;
	char map[51][51];

	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cin >> map[i][j];
		}
	}


	//Todo : 가로체크, 세로 체크해서 , 둘중에 많은 거 선택하면 됨.

	for(int i = 0; i < N; ++i){
		//가로체크
		for(int j = 0; j < M; ++j){
			if(map[i][j] == 'X') {
				row_check = true;
				break;
			}
		}
		if(row_check == false) empty_row++;
		row_check = false;
	}

	for(int i = 0; i < M; ++i){
		for(int k = 0; k < N; ++k){
			if((map[k][i]) == 'X') {
				column_check = true;
				break;
			}
		}
		if(column_check == false) empty_col++;
		column_check = false;
	}

	if(empty_row >= empty_col) cout << empty_row;
	else cout << empty_col;

	return 0;
}
