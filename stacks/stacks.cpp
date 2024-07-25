#include <iostream>
#include <stack>
using namespace std;

string reverse(string C, int n){
    stack<char> S;
    for(int i=0;i<n;i++){
        S.push(C[i]);
    }
    for(int j = 0; j<n;j++){
        C[j] = S.top();
        S.pop();
    }
    return C;
}

int main(){
    string C;
    cout<<"Enter string: ";
    cin>>C;
    cout<<endl;
    C = reverse(C, C.length());
    cout<<"Reversed String: "<<C<<endl;
}

// Time and space complexity is O(n) and O(n)