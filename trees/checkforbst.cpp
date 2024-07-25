#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

bool isSubTreeLesser(node* root, int value){
    if(root == NULL) return true;
    if(root-> data <= value && isSubTreeLesser(root-> left, value) && isSubTreeLesser(root->right, value)) return true;
    else return false;
}
bool isSubTreeGreater(node* root, int value){
    if(root == NULL) return true;
    if(root-> data >= value && isSubTreeGreater(root-> left, value) && isSubTreeGreater(root->right, value)) return true;
    else return false;
}

bool checkBST(node* root){
    if(root == NULL) return true;
    if (isSubTreeLesser(root-> left, root-> data) && isSubTreeGreater(root->right, root->data) && checkBST(root->left) && checkBST(root->right)) return true;
    else return false;
}

int main(){

}