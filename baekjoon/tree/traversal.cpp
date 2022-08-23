#include <iostream>
#include <vector>

using namespace std;

#define Max 26

//node 선언
typedef struct {
	char left;
	char right;
} Node;
//포인터 배열
Node* v[Max];

int N;

void pre_order(char node){
	if(node == '.') return;
	cout << node; 
	pre_order(v[node - 'A'] -> left);
	pre_order(v[node - 'A'] -> right);
}

void in_order(char node){
	if(node == '.') return;
	in_order(v[node - 'A'] -> left);
	cout << node; 
	in_order(v[node - 'A'] -> right);
}

void post_order(char node){
	if(node == '.') return;
	post_order(v[node - 'A'] -> left);
	post_order(v[node - 'A'] -> right);
	cout << node; 
}

int main(){
	
	cin >> N;
	
	for(int i = 0; i < N; ++i){
		char rt,l,r;

		cin >> rt >> l >> r;
		//동적할당
		Node* nd = new Node;
		nd -> left = l;
		nd -> right = r;
		v[rt - 'A'] = nd;
	}

	pre_order('A');
	cout << endl;
	in_order('A');
	cout << endl;
	post_order('A');

	return 0;
}
