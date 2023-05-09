#include <iostream>

using namespace std;


class Simple{
    private :
        int m_id;
    
    public :
        Simple(int id){
            setID(id);

            cout << this << endl;
        }
        
        void setID(const int& id){
            m_id = id;
        }

        int getID(){
            return m_id;
        }



};

int main(){

    Simple s1(1), s2(2);
}