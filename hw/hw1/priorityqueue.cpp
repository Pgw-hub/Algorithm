#include <iostream>

using namespace std;

struct Element {
    string name;
    float score;

    // Element(string k, float v){
    //     name = k;
    //     score = v;
    // };
};

struct Heap {
    Element* nodes;
    int N;
    
    Heap(){
        nodes = (Element*)malloc(30 * sizeof(Element));
        N = 0;
    };
};

void grow(Heap* h,string key, float value);
void trim(Heap* h);
void printall(Heap* h);
void change(Heap* h);
void swim(Heap* h,int index);
void sink(Heap* h,int index);
void swap(Heap* h,int i,int j);

int main(){

    char c;
    string key;
    float value;
    Heap* h = new Heap;

    do{

        cout << "**********MENU**********" << endl; 
        cout << "I : Insert new element into queue" << endl;
        cout << "D : Delete element with smallest key from queue." << endl;
        cout << "C : Decrease key of element in queue" << endl;
        cout << "P : Print out all elements in queue" << endl;
        cout << "Q : Quit" << endl << endl;
        cout << "Choose menu : ";

        cin >> c;

        switch(c){
            case 'I' :
                cout << "Enter name of element" << endl;
                cin >> key;
                cout << "Enter key value of element" << endl;
                cin >> value;
                grow(h,key,value);
                swim(h,h->N);
                break;
            case 'D' :
                trim(h);
                break;
            case 'C' :
                change(h);
                break;
            case 'P' :
                printall(h);
                break;
            case 'Q' ://완료
                cout << "Thank you, Bye!" << endl;
                break;
        }
    } while( c != 'Q');

    return 0;
}


// fuction
// replace(C),
// swim , swap , sink, grow(I), printall(P), trim(D)

void grow(Heap* h,string key, float value){
    // h -> nodes[h->N].name = key;
    // h -> nodes[h->N].score = value;
    h -> N++;
    h -> nodes[h->N] = {key, value};
    cout << "New element [" << h->nodes[h->N].name << "," << h->nodes[h->N].score << "]" << " is inserted." << endl << endl;
    
}

void trim(Heap* h){
    cout << "[" << h->nodes[1].name << "," << h->nodes[1].score << "]" << " is deleted." << endl << endl;
    swap(h,1,h->N);
    h -> N--;
    sink(h,1);
}

void change(Heap* h){
    int key;
    float new_score;

    while(1){
        cout << "Enter indx of element :" << endl;
        cin >> key;
        cout << "Enter new key value :" << endl;
        cin >> new_score;

        key = key + 1;//원래 index보다 1씩 큼.

        if(new_score > h -> nodes[key].score){
            cout << "new key value is higher than original one." << endl << "Enter proper input" << endl;
        }
        else{
            h->nodes[key].score = new_score;
             swim(h,key);
             break;
        }
    }
}

void printall(Heap* h){
    for(int i = 1; i <= h->N; i++){
        cout << "[" << h->nodes[i].name << "," << h->nodes[i].score << "]" << "  ";
    }
    cout << endl;
}

void swim(Heap* h,int index){
    //부모가 자식보다 크면 바꿈. 
    //부모는 현재 인덱스에서 /2한것임.
//    if(index <= 2) return;
//    int c_i = index;
//    int p_i = c_i/2;
//   I if(h->N >1)
    while(h->nodes[index/2].score > h->nodes[index].score && index >1){
        //바꾸고, 그 바꾼 친구의 조부모와 또 비교해야함. 그럼 인덱스를 
        swap(h,index/2,index);
        index = index/2;
//        c_i = p_i;//스왑되면 부모를 자식으로 만들고,
//        p_i = c_i/2;// 조부모님을 결정해줌.
    }
}

void sink(Heap* h,int index){

    while( index * 2 <= h -> N){
        int j = 2 * index;

        if( j < h->N && h->nodes[j].score > h-> nodes[j+1].score ) j = j + 1;

        if(h->nodes[index].score > h->nodes[j].score){
            swap(h,index,j);
            index = j;
        }
        else break;
    }
}

void swap(Heap* h,int i,int j){
    Element temp = h -> nodes[i];
    h -> nodes[i] = h -> nodes[j];
    h -> nodes[j] = temp;
}
