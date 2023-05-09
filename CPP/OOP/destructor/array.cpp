#include <iostream>

using namespace std;

class IntArray{

    private :
        int* m_arr = nullptr;
        int m_len;

    public :
        IntArray(const int& len_input){
            m_len = len_input;
            m_arr = new int(len_input);
            cout << "constructor" << endl;
        }

        ~IntArray(){
            if(m_arr != nullptr)
                delete[] m_arr;
        }

};

int main(){

    while(1){
        IntArray(100);
    }



}