#include <iostream>

using namespace std;

void CountingSort(int* a, int k, int size);

int main(){

	int A[8] = {2,5,3,0,2,3,0,3};
	int k = 5;
	int size = (sizeof(A) / sizeof(A[0]) );
	int n,k;
	//int n;

	//cin >> n;

	//for(int i = 0; i < n; i++){
	//	A[i] = rand() & 
	//}
	
	CountingSort(A, k, size);

	return 0;
}

void CountingSort(int* a, int k, int size){
//	`cout << a[1] << endl;
	int C[1001] = {0};
	int B[1001] = {0};

	//counting C // counting할떄 0부터 size전까지 세야함.
	cout << "a = ";
	for(int i = 0; i < size; i++){
		C[a[i]] = C[a[i]] + 1;
		cout << a[i] << " ";
	}
	cout << endl;
	
	//print C
	cout << "C = ";
	for(int i = 0; i <= k; i++){
		cout << C[i] << " ";
	}
	cout << endl;

	//accumulate C // 이건같음
	for(int i = 1; i <= k; i++){
		C[i] = C[i] + C[i-1];
	}

	cout << "C_accum = "; // 이것도 같음. 
	for(int i = 0; i <= k; i++){
		cout << C[i] << " ";
	}
	cout << endl;

	for(int j = size - 1; j >= 0; j--){//이건 size -1부터 0까지 거꾸로 해야함.
		B[C[a[j]]] = a[j];
		C[a[j]] = C[a[j]] - 1;
		// cout << j << endl;
	}
	
	cout << "B = ";
	for(int i = 1; i <= size; i++){
		cout << B[i] << " ";
	}
	

}

