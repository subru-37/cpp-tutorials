// Stacks are abstract data types
// Last in is removed first out
// insertions and deletion (push and pop) on end of stack 
// operations are :- push, pop, top, isEmpty for O(1)
// Function calls with recursion and subfunctions
// undo operation using stacks 
// Balanced parantheses using stacks

#include <iostream>
#include <cmath>
#include <string>
// #include <objidl.h>
using namespace std;
const int max_size = 100;
int A[max_size];
int top = -1;
void push(int x){
    if(top == max_size - 1){
        cout<<"Overflow"<<endl;
        return;
    }
    A[++top] = x;
}

void pop(){
    if(top == -1){
        cout<<"Empty List"<<endl;
        return;
    }
    top--;
}
void print(){
    int i;
    cout<<"Stack: "<<endl;
    for(i=0;i<=top;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main(){
    push(2);print();
    push(2);print();
    push(2);print();
    push(2);print();
}
