//lecture : slide chapter 8
//blog : no blog
//book : no book

#include <iostream>

using namespace std;

void CountingSort(int* a, int k, int size);

int main(){

	int A[1001] = {0};
	int seed,n,k;
	
	cout << "insert seed , n , k" << endl;
	cin >> seed >> n >> k;

	srand(seed);

	for(int i = 0; i < n; i++){
		A[i] = rand() % k;
	}
	
	CountingSort(A, k, n);

	return 0;
}

void CountingSort(int* a, int k, int size){
	int C[1001] = {0};
	int B[1001] = {0};

	//counting C
	cout << "A = ";
	for(int i = 0; i < size; i++){
		C[a[i]] = C[a[i]] + 1;
		cout << a[i] << " ";
	}
	cout << endl;
	
	//print C
	// cout << "C = ";
	// for(int i = 0; i <= k; i++){
	// 	cout << C[i] << " ";
	// }
	// cout << endl;

	//accumulate C
	for(int i = 1; i <= k; i++){
		C[i] = C[i] + C[i-1];
	}

	//print C_accum
	// cout << "C_accum = ";
	// for(int i = 0; i <= k; i++){
	// 	cout << C[i] << " ";
	// }
	// cout << endl;

	for(int j = size - 1; j >= 0; j--){
		B[C[a[j]]] = a[j];
		C[a[j]] = C[a[j]] - 1;
	}

	cout << "After counting sort..." << endl;
	cout << "B = ";
	for(int i = 1; i <= size; i++){
		cout << B[i] << " ";
	}
	

}

