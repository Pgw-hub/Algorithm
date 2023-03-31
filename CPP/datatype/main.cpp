#include <iostream>

using namespace std;

int main(){
    short s = 1;

    cout << numeric_limits<short>::max() << endl; 
    cout << numeric_limits<short>::min() << endl;  

    s = 32767;
    s = s + 5;
    cout << s;
}