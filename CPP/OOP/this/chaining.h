#include <iostream>

class Calc{
    private :
        int m_num;

    public :
        Calc(const int& input)
        : m_num(input) 
        { 
        }

        Calc& add(const int& input);
        Calc& sub(const int& input);
        Calc& mult(const int& input);
        void print();
};


        
