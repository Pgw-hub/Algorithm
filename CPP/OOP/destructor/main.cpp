#include <iostream>

using namespace std;

class Simple{
    private :
        int m_num;

    public :
        Simple(const int &input_num){
            m_num = input_num;
            cout << "this is constructor " << m_num << endl;
        }

        ~ Simple(){
            cout << "this is destructor " << m_num <<endl;
        }
};

int main(){
    Simple* s1 = new Simple(0);
    Simple s2(1);

    delete s1;

    return 0;
}