#include <iostream>


using namespace std;

struct Node {
	int data;
	Node* next;

	//constructor
	Node(const int i = 0; Node* n  = nullptr){
		data = i, next = n;
	}

	//deconstructor
	~Node(){}
};

Node* push(Node* p, int val){
	p = new Node{val, p};
	return p;
}

void show(Node* p){
	for(Node* curr= p; curr != nullptr; curr = curr -> next){
		cout << "\t" << curr -> data;
	}
}

int main(){
	Node* stack = nullptr;
	
	while(1){
		int val;
		cin >> val;
		if(val == 99) break;

		stack = push(stack, val);
	}

	show(stack);


}

