#include <iostream>
#include <cstdlib>


using namespace std;

int main(){

    int a , b;

    cin >> a >> b;
    a = a - 1;
    b = b - 1;
    int r = abs((a / 4) - (b / 4));
    int c = abs((a % 4) - (b % 4));

    cout << r + c;

    return 0;
}