#include <iostream>
#include <cmath>
#include <string>
// #include <objidl.h>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};
struct node* head;
node* getNewNode(int x){
    node* temp = new node();
    temp -> data = x;
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}
node* insertAtHead(node* head, int x){
    node* new_node = getNewNode(1);
    if(head == NULL){
        head = new_node;
        return head;
    }
    head -> prev = new_node;
    new_node -> next = head;
    head = new_node;
    return head;
}
node* insertAtEnd(node* head, int mydata){
    node* new_node = getNewNode(mydata);
    if(head == NULL){
        head = new_node;
        return head;
    }
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    new_node -> next = NULL;
    temp -> next = new_node;
    new_node -> prev = temp;
    return head;
}
void print_nodes(node* ref){
    node* temp = ref;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}
int main(){
    head = NULL;
    head = insertAtEnd(head, 2);
    print_nodes(head);
    head = insertAtEnd(head, 3);
    print_nodes(head);
    head = insertAtEnd(head, 4);
    print_nodes(head);
    head = insertAtEnd(head, 5);
    print_nodes(head);
}

