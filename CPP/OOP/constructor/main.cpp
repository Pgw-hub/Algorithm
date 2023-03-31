#include <iostream>

using namespace std;

class Fraction{

    private :
        int m_numerator;
        int m_denominator;

    public :

        Fraction(const int & num_input, const int & denom_input){
            m_numerator = num_input;
            m_denominator = denom_input;
            
            cout << "this is constructor" << endl;
        }
        void print(){
            cout << m_numerator << " / " << m_denominator << endl;
        }

};



int main(){

    Fraction frac(5,54);

    frac.print();

    return 0;
}`