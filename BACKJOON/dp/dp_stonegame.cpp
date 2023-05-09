#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int num;
    int g_count[100]; 
    g_count[0] = 0;
    g_count[1] = 1;
    g_count[2] = 2;
    
    cin >> num;

    for(int i=3; i<=num; i++){
        g_count[i] = min(g_count[i-1]+1,g_count[i-3]+1);
    }

    if(g_count[num]%2 == 0) cout << "CY";
    else cout << "SK";

    return 0;
}