#include <iostream>
#include <stack>
using namespace std;

struct node{
    int data;
    node* link;
};

node* head;

void reverse(){
    stack<node*> S;
    node* temp = head;
    while(temp){
        S.push(temp);
        temp = temp -> link;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()){
        temp -> link = S.top();
        S.pop();
        temp = temp -> link;
    }
    temp -> link = NULL;
}

void printReverse(){
    
}

int main(){

}