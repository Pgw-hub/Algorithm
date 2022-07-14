#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int N, M;
	int pp,np;
	int pc, nc;
	int pmin = 9999999;
	int nmin = 9999999;

	cin >> N >> M;

	pc = N / 6; // 패키지로 살 수있는 갯수
	nc = N % 6; // 패키지로 사면 남은 갯수

	while(M--){
		cin >> pp >> np;
		pmin = min(pmin,pp);
		nmin = min(nmin,np);
	}

	//1.낱개로 더하기 2.묶음 + 낱개 3. 묶음 + 묶음.
	int cand1 = nmin * N;
	int cand2 = (pmin * pc) + (nmin * nc);
	int cand3 = pmin * (pc + 1);

	cout << min({cand1,cand2,cand3}) << endl;

	return 0;
}
