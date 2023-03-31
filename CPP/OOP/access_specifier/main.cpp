#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date{

    private :
        int m_month;
        int m_day;
        int m_year;

    public :
        void setDate(const int & month_input, const int & day_input, const int & year_input){
            m_month = month_input;
            m_day = day_input;
            m_year = year_input;
        }
        void printDate(){
            cout << m_day << " " << m_month << " " << m_year << endl;
        } 
        void copyFrom(const Date &original){
            m_month = original.m_day;
            m_day = original.m_day;
            m_year = original.m_year;
        }
};

int main(){

    Date today;
    today.setDate(6,5,2023);
    today.printDate();
    
    Date copy;
    copy.copyFrom(today);
    copy.printDate();

    return 0;
}
