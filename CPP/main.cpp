#include <iostream>
#include "include/module.h"

using namespace std;

int main(){
    cout << mySpace::InnerSpace::add(3,5) << endl;
    cout << mySpace::InnerSpace::sub(5,3) << endl;
    return 0;
}