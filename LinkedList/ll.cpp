#include <iostream>
#include <cmath>
#include <string>
// #include <objidl.h>
using namespace std;

struct node{
    int data;
    node* link;
};
node* start(node* temp){
    temp -> data = 1;
    temp -> link = NULL;
    return temp;
}
void print_nodes(node* ref){
    node* temp = ref;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp -> link;
    }
}
void append(node* head, int mydata){
    node* new_node = new node();
    node* temp = head;
    while(temp -> link != NULL){
        temp = temp -> link;
    }
    new_node -> data = mydata;
    new_node -> link = NULL;
    temp -> link = new_node;
}
void insertAtLoc(node* head, int n, int mydata){
    node* new_node = new node();
    new_node -> data = mydata;
    new_node -> link = NULL;
    if (n==1){
        new_node -> link = head;
        head = new_node;
        return;
    }
    node* temp = head;
    for(int i=0;i<n-2;i++){
        temp = temp -> link;
    }
    new_node -> link = temp->link;
    temp -> link = new_node;
}
node* insert_at_beginning(node* head, int mydata){
    node* new_node = new node();
    new_node -> link = head;
    new_node -> data = mydata;
    head = new_node;
    return head;
}
node* deleteAtNode(node* head, int loc){
    node* temp = head;
    cout<<"Delete node at: "<<loc<<" position"<<endl;
    if(loc == 1){
        head = temp -> link;
        delete(temp);
        return head;
    }
    for(int i=0;i<loc-2;i++){
        temp = temp -> link;
    }
    cout<<"Deleted: "<<temp->link->data<<endl;
    node* addrToDelete = temp -> link;
    temp -> link = temp -> link -> link;
    delete(addrToDelete);
    return head;
}

node* reverseLL(node* head){
    node* previous = NULL;
    node* current = head;
    node* next;
    while(current){
        next = current -> link; // save next node address
        current -> link = previous; //reverse current node address to the one before it
        previous = current; // for next iteration, previous node will be current node
        current = next; // and current node will be next node
    }
    head = previous;
    return head;
}
node* recursiveReverse(node* p){
    if (p-> link == NULL){
        node* head = p;
        return head;
    }
    node* head = recursiveReverse(p->link);
    node* q = p-> link;
    q-> link = p;
    p-> link = NULL;
    return head;
}
int main(){
    node* node1 = new node();
    node* head = start(node1);
    append(head, 2);  
    append(head, 3);  
    head = insert_at_beginning(head, 0);
    insertAtLoc(head, 4, 69);
    print_nodes(head);
    head = deleteAtNode(head, 1);
    print_nodes(head);
    head = reverseLL(head);
    print_nodes(head);
    head = recursiveReverse(head);
    print_nodes(head);
}
