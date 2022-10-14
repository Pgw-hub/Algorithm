#include <iostream>
using namespace std;
int stack[100000];
char op[100000];

int main() {  
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int N; // n 입력 받기
  cin >> N;

  int element = 1;
  int top = 0; // stack top
  int top2 = 0; // operation top
  int result = 1; // 결과 저장을 위한 변수
  
  while (N != 0) {
    // cout << "현재 top은 " << top << '\n';
    // cout << "새로운 top 원소는 " << stack[top-1] << endl;
    // cout << "현재 element는 " << element << '\n';
    int num;
    cin >> num;
    // cout << num << "을 입력받았다\n";

    if (stack[top-1] < num && element > num) {
      result = 0;
      // break;
    }
    if (num >= element) {
      while (element <= num) {
        // cout << "push " << element << '\n';
        stack[top++] = element;
        element++;
        // cout << "+" << '\n';
        op[top2++] = '+';
      }
    }

    int index = top-1;
    // cout << "now index is " << top << '\n';
    // cout << "비교할 수는 " << stack[index] << '\n';
    
    while (index >= 0) {
      if (stack[index] == num) {
        // cout << 
        top--;
        // cout << "pop " << stack[top] << '\n';
        // cout << "-" << '\n';
        op[top2++] = '-';
      }
      else if (stack[index] > num) {
        top--;
        // cout << "pop " << stack[top];
        // cout << "-" << '\n';
        op[top2++] = '-';
      }
      // else result = 0;

      index--;
    }
    N--;
  }
  
  if (result == 0) cout << "NO";
  
  else for (int i = 0; i < top2; i++) {
    cout << op[i] << '\n';
  }
  
  return 0;
}