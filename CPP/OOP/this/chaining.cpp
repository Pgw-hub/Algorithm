#include "chaining.h"

using namespace std;

Calc& Calc::add(const int& input){
            m_num += input;
            return *this;
        };

Calc& Calc::sub(const int& input){
            m_num -= input;
            return *this;
        }

Calc& Calc::mult(const int& input){
    m_num *= input;
    return *this;
}

void Calc::print(){
            using namespace std;
            cout << m_num << endl;
        }