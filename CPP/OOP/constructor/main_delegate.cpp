#include <iostream>

using namespace std;


class Student{
    private : 
        int _num;
        string _name;
    public : 
        Student(const string& name_input)
        {
            init(0,name_input);
        }

        Student(const int& num_input, const string& name_input)
        {   
            init(num_input, name_input);
        }

        void init(const int& num_input, const string& name_input){
            _num = num_input;
            _name = name_input;
        }
        
        void print(){
            cout << _num << " " << _name << endl;
        }
};

int main(){

    Student stu(0,"Geonwoo");

    stu.print();

}