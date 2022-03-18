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
                break;
            case 'P' :
                printall(h);
                break;
            case 'Q' ://완료
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
    swap(h,h->N,1);
    h -> N--;
    sink(h,1);
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
    int c_i = index;
    int p_i = c_i/2;
    if(h->N >1)
    while(h->nodes[p_i].score > h->nodes[c_i].score && p_i >0){
        //바꾸고, 그 바꾼 친구의 조부모와 또 비교해야함. 그럼 인덱스를 
        swap(h,p_i,c_i);
        c_i = p_i;//스왑되면 부모를 자식으로 만들고, 
        p_i = c_i/2;// 조부모님을 결정해줌.
    }
}

void sink(Heap* h,int index){
    //자식과 비교하면서 자신이 자식보다 크면, swap();
    //언제까지? 자식과 비교해서 클때까지 && 젤 leaf가 아닐떄
    //parent index = p_i
    //leftchildindex = lci
    //rightchildindex = rci
    int p_i = index;
    int lci = (index*2);
    int rci = (index*2)+1;
    int check = 0;

    while( p_i * 2 <= h -> N){
        if(h->nodes[p_i].score > h->nodes[lci].score){
            swap(h,p_i,lci);
            p_i = lci;
            check = 1;
        }
        if(h->nodes[p_i].score < h->nodes[rci].score){
            swap(h,p_i,rci);
            p_i = rci;
            check = 1;
        }
        if(check == 1){
            lci = (p_i*2);
            rci = (p_i*2)+1;
            check = 0;
        }
        else break;
    }
}

void swap(Heap* h,int i,int j){
    Element temp = h -> nodes[i];
    h -> nodes[i] = h -> nodes[j];
    h -> nodes[j] = temp;
}