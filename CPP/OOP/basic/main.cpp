#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Friend{
    public : // access specifier(public, private, protected)
        string name;
        string address;
        int age;
        double height;
        double weight;

        void print(){
            cout << name << " " << age << endl;
        }
};

int main(){

    Friend jj{"Jack Jack", "Uptown", 2, 30, 30};

    jj.print();

    vector<Friend> my_friends;
    my_friends.resize(2);

    for(auto &ele : my_friends)
        ele.print();

    return 0;
}