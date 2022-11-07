#include <iostream>

using namespace std;

int N;
string s;

int main(){
    
    cin >> N;

    while(N--){
        cin >> s;
        for(int i = 0; i < s.size(); ++i){
            s[i] = tolower(s[i]);
        }
        cout << s << endl;
    }      

    return 0;
}