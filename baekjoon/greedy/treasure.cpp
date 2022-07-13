#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
	int n;
	int a, b;
	priority_queue<int> pq1, pq2;

	cin >> n;

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < n; j++){
			if( i == 0){
				cin >> a;
				pq1.push(-a);
			}
			else{
				cin >> a;
				pq2.push(a);
			}
		}
	} 

	int sum = 0;
	while(!pq1.empty()){
		sum += ( -pq1.top() * pq2.top() ) ;
		pq1.pop();
		pq2.pop();
	}

	cout << sum; 


return 0;
}
