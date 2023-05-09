#include <iostream>

using namespace std;

int main(){

    int a = 5; 
    int* ptr = nullptr;

    ptr = &a;
    cout << *ptr << endl;

    int& ref = a;

    ref = 10; 

    cout << &ref << " " << ref << " " << a << " " << &a << endl;

    return 0;
}