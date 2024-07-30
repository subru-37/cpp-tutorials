#include <iostream>
#include <cmath>
#include <string>
// #include <objidl.h>
using namespace std;

struct node{
    int data;
    node* link;
};
node* head;
node* getNewNode(int x){
    node* temp = new node();
    temp -> data = x;
    temp -> link = NULL;
    return temp;
}
void push(int x){
    node* temp = getNewNode(x);
    temp -> link = head;
    head = temp;
}
void print_nodes(node* ref){
    node* temp = ref;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> link;
    }
    cout<<endl;
}
void pop(int x){
    node* temp;
    if(head == NULL) return;
    temp = head;
    head = head -> link;
    delete(temp);
}

int main(){
    head = getNewNode(2);
    push(5);
    push(5);
    push(5);
    push(5);
    print_nodes(head);

}