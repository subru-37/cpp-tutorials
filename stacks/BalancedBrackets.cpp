#include <iostream>
#include <stack>
using namespace std;

struct node{
    int data;
    node* link;
};

bool checkbrackets(string C){
    int n = C.length();
    stack<char> S;
    for(int i=0;i<n;i++){
        if(C[i]=='(' || C[i]=='[' || C[i]=='{'){
            S.push(C[i]);
            // cout<<C[i]<<endl;       
        }
        else if (C[i] == ')' || C[i] == ']' || C[i] == '}'){
            // cout<<S.top()<<" "<<C[i]<<endl;
            if(!S.empty()){
                if((C[i]==')' && S.top() == '(') || (C[i]=='}' && S.top() == '{') || (C[i]==']' && S.top() == '[')){
                    S.pop();
                    continue;
                }
                else{
                    return false;
                } 
            }
        }
    }
    // cout<<S.empty()<<endl;
    return S.empty() ? true : false ;
}

int main(){
    string C = "()(){[][]}";
    bool check = checkbrackets(C);
    cout<<check<<endl;
}