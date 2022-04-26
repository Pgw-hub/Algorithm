#include <iostream>

using namespace std;

int main(){
    int K,D,A;
    char slash;
    
    cin >> K >> slash >> D >> slash >> A;
    
    if(D == 0 || (K + A < D)){
        cout << "hasu";
    }
    else
        cout << "gosu";
    return 0;
}
