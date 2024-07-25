#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

//Binary search trees
struct node{
    int data;
    node* left;
    node* right;
};

node* rootpr = NULL;

node* createNode(int x){
    node* new_node = new node();
    // node* new_node = (node*)malloc(sizeof(node));
    new_node -> data = x;
    new_node -> left = NULL;
    new_node -> right = NULL;
    return new_node;
}

//bst
bool search(node* root, int data){
    if(root == NULL) return false;
    else if(data == root-> data) return true;
    else if(data >= root->data) return search(root->right, data); 
    else return search(root->left, data);
}
// Function to traverse the tree in preorder
// and check if the given node exists in it
// binary tree
bool ifNodeExists(struct node* root, int key)
{
    if (root == NULL)
        return false;
 
    if (root->data == key)
        return true;
 
    /* then recur on left subtree */
    bool res1 = ifNodeExists(root->left, key);
    // root found, no need to look further
    if(res1) return true; 
 
    /* root is not found in left, 
    so recur on right subtree */
    bool res2 = ifNodeExists(root->right, key);
 
    return res2;
}

node* insertNode(node* root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    else if(data <= root-> data) root-> left = insertNode(root-> left, data); 
    else root-> right = insertNode(root->right, data); 
    return root;
}


int min(node* root, int data){
    node* current = root;
    if(root == NULL){
        cout<<'error'<<endl;
        return -1;
    }
    while(current -> left){
        current = current -> left;
    }
    return current -> data;
}


int max(node* root, int data){
    node* current = root;
    if(root == NULL){
        cout<<'error'<<endl;
        return -1;
    }
    while(current -> right){
        current = current -> right;
    }
    return current -> data;
}


int height(node* root){ //O(n) - time complexity
    if(root == NULL){
        return  -1;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return max(leftheight, rightheight) + 1;
}

//transversing 
// Breadth first and depth first


void levelOrder(node* root){
    if(root == NULL) return;
    queue<node*> Q;
    //while there is atleast one discovered node in queue
    while(!Q.empty()){
        node* current = Q.front();
        cout<<current->data<<" ";
        if(current -> left) Q.push(current -> left);
        if(current -> right) Q.push(current -> right);
        Q.pop(); //removing element at the front
    }
}

void preOrder(node* root){
    //root, left, right - preorder
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
    //O(n) - time complexity
    //O(h) in stack - space complexity
}

void inOrder(node* root){
    //left, root, right - preorder
    if(root == NULL) return;
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
    //O(n) - time complexity
    //O(h) in stack - space complexity
}

void postOrder(node* root){
    //left, right, root - preorder
    if(root == NULL) return;
    preOrder(root->left);
    preOrder(root->right);
    cout<<root->data<<" ";
    //O(n) - time complexity
    //O(h) in stack - space complexity
}

int main(){
    node* root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 25);
    root = insertNode(root, 2);
    root = insertNode(root, 7);
    root = insertNode(root, 18);
    int number;
    cout<<"Enter number to search: "<<endl;
    cin>>number;
    bool check = search(root, number);
    cout<<"Is the number present: "<<check<<endl;
}