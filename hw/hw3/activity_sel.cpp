#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef struct{
    int start;
    int finish;
} Time;

void printpair(Time time);
bool cmp(const Time &t1, const Time &t2);
int greedy(Time* t);
#define SIZE 20

int main(){

    Time t[SIZE];
    srand(408);
    //make time pair
    int i = 0;
    int N = SIZE;
    while(i != N){
        int start;
        int finish;
        start = rand() % SIZE * 10;
        finish = rand() % SIZE * 10;
        if(finish > start) {
            t[i].start = start;
            t[i].finish = finish;
            i++;
        }
    }
    
    for(int i=0; i < N; i++){
        printpair(t[i]);
    }
    cout << endl;


    //greedy
    int temp = greedy(t);
    cout << "max num of activity is = " << temp;
    
}


void printpair(Time time){
    cout << "("<< time.start << " , " << time.finish << ")"<< endl; 
}

int greedy(Time* t){
    cout << "****Greedy****" << endl;
    //sorting
    sort(t,t+SIZE,cmp);
    int takes = 1;
    int prev = t[0].finish;
    for(int i = 1; i < SIZE; i++){
        if(t[i].start >= prev) {
            cout << "pair is ";
            printpair(t[i]);
            cout << endl;
            takes++;
            prev = t[i].finish;
        }
    }
    return takes;
}

bool cmp(const Time &t1, const Time &t2){
    if(t1.finish < t2.finish){
        return true;
    }
    else if(t1.finish == t2.finish){
        return t1.start < t2.start;
    }
    else{
        return false;
    }
}

