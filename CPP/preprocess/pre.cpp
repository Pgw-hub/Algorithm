#include <iostream>

void doSomeThing(){

    using namespace std;

    #ifdef GEONWOO
    cout << "Geonwoo is here" << endl;
    #else
    cout << "Geonwoo is not here" << endl;
    #endif

}