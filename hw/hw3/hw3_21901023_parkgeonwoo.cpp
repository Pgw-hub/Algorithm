#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

typedef struct{
    int start;
    int finish;
} Time;
// #define SIZE 100


void printpair(Time time);
void printpair(Time* time, int N);
// void print_dptable(int t[][SIZE + 2], int N);
bool cmp(const Time &t1, const Time &t2);
int greedy(Time* t, int SIZE);
int dp(Time* t, int SIZE);
int sub_main(int SIZE);

int main(){
    int num[5] = {10,100,1000,10000,100000};

    cout << "---------------------------------------------------------------" << endl;
    cout << " Number   |" << "          Execution time in microseconds" << endl;
    cout << " of jobs  |" << "     Greedy             | Dynamic Programming" << endl;
    cout << "---------------------------------------------------------------" << endl;
    int n = 0;
    while(1){
        printf("%9d | \t",num[n]);
        sub_main(num[n]);
        n++;
        if(n == 5) break;
    }
    cout << "---------------------------------------------------------------" << endl;
}

int sub_main(int SIZE){

    Time t[SIZE + 2];
    srand(408);
    //make time pair
    t[0].start = 0;
    t[0].finish = 0;
    t[SIZE + 1].start = SIZE * 10;
    t[SIZE + 1].finish = SIZE * 10;
    int i = 1;
    int N = SIZE + 1;
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
    
    //cout << "****Making random pair****" << endl << endl;
    //printpair(t,SIZE);
    //cout << endl << endl;
    
    //GREEDY
    clock_t startTime = clock();
    int temp = greedy(t,SIZE);
    clock_t endTime= clock();
    endTime = endTime - startTime;
    float timeinSeconds = endTime /  (float) CLOCKS_PER_SEC;
    cout << setw(10)  << timeinSeconds << "              ";
 
    //sorted pair list for dp
    //cout << "****USING SORTED LIST FOR DP****" << endl << endl;
    //printpair(t,SIZE);


    //DP
    if(SIZE < 10000){
        startTime = clock();
        temp = dp(t,SIZE);
        endTime= clock();
        endTime = endTime - startTime;
        timeinSeconds = endTime /  (float) CLOCKS_PER_SEC;
        cout << timeinSeconds << endl;
    }
    else{
        cout << endl;
    }
}


//greedy
int greedy(Time* t,int SIZE){
    // cout << "****GREEDY****" << endl;
    //sorting
    sort(t,t+SIZE,cmp);

    //define start condition
    int takes = 1;
    int prev = t[1].finish;
    //cout << "pair is";
    //printpair(t[1]);
    //cout << endl;

    for(int i = 2; i < SIZE + 1; i++){
        if(t[i].start >= prev) {
            //cout << "pair is ";
            //printpair(t[i]);
            //cout << endl;
            takes++;
            prev = t[i].finish;
        }
    }
    return takes;
}



int dp(Time* t, int SIZE){
    // cout << "****DP****" << endl;
    //generating dptable c with additional a0, a11
    
    int c[1000 + 2][1000 + 2] = {};


    int i,j,k;
    int temp;

    //dp start with second diagonal
    for(j = 2; j <= SIZE + 2; j++){
        for(i = 1; i < j; i++){
            for(k = i+1; k < j; k++){
                if(t[k].start >= t[i].finish && t[k].finish <= t[j].start){
                    temp = c[i][k] + c[k][j] +1;
                    if(c[i][j] < temp){
                        c[i][j] = temp;
                    }
                }
            }
        }
    }
    //print_dptable
    //print_dptable(c,SIZE + 2);

    return c[1][SIZE + 1] + 1;
};    

//printing dptable
// void print_dptable(int t[][SIZE + 2], int N){
//     for(int i = 0; i < N; i++) cout << i << "  ";
//     cout << endl;
//     cout << "-------------------------------------" << endl;
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < N; j++){
//             cout << t[i][j] << "  ";    
//         }
//         cout << endl;
//     }
// }

//compare function in ::sort()
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

//print sing pair
void printpair(Time time){
    cout << "("<< time.start << " , " << time.finish << ")"<< endl; 
}

//print all pairs
void printpair(Time* time, int N){
    for(int i =1; i < N + 1; i++ ){
        cout << "("<< time[i].start << " , " << time[i].finish << ")"<< endl; 
    }
}