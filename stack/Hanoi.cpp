#include <iostream>
#include <stack>

using namespace std;

stack<int> A;
stack<int> B;
stack<int> C;

void hanoi(int N,stack<int>&,stack<int>&,stack<int>&);
void print_stack(stack<int>);
void print_all();


int main() {
    int N;
    cout << "Please enter N:" << endl;
    cin >> N;
    for(int i=N;i>0;i--)
        A.push(i);

    print_all();
    hanoi(N,A,C,B);

    return 0;
}


void hanoi(int N,stack<int>& from,stack<int>& to,stack<int>& others){
    if(N == 1){
        cout << "=======================" << endl;
        int top = from.top();
        to.push(top);
        from.pop();
        print_all();
        return ;
    }
    hanoi(N-1, from, others, to);
    hanoi(1, from, to, others);
    hanoi(N-1, others, to, from);
}

void print_stack(stack<int> s){
    stack<int> tmp;
    while(!s.empty()){
        int top = s.top();
        tmp.push(top);
        s.pop();
    }
    while(!tmp.empty()){
        int top = tmp.top();
        tmp.pop();
        cout << top << " ";
    }
    cout << endl;
}

void print_all(){
    cout << "A:";
    print_stack(A);
    cout << "B:";
    print_stack(B);
    cout << "C:";
    print_stack(C);
}
