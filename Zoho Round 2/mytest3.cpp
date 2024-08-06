#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <c++/13/stdlib.h>

// #include <bit>
using namespace std;

int main(){
    string s = "3[a2[i9[c]]]";
    // string s = "3[a]2[bc]";
    // string s = "2[abc]3[cd]ef";
    string temp = "";
    stack<char> mystack;
    string result = "";
    string mulstring = "";
    for(int i = 0; i<s.size(); i++){
        if(s[i]!=']'){
            mystack.push(s[i]);
        }else{
            while(mystack.top()!='['){
                temp += mystack.top();
                mystack.pop();
            }
            mystack.pop();
            reverse(temp.begin(), temp.end());
            string mynumber = "";
            char c = mystack.top();
            while(!isalpha(c) && c!= '[' && !mystack.empty()){
                mynumber += c;
                mystack.pop();
                if(!mystack.empty()) c = mystack.top();
            }
            reverse(mynumber.begin(), mynumber.end());
            int iterations = std::stoi(mynumber);
            if(mystack.empty()){
                for(int i = 0; i<iterations; i++){
                    result += temp;
                }
                temp = "";
            }else{
                for(int i = 0; i<iterations; i++){
                    mulstring += temp;
                }
                temp = mulstring;
            }
        }
    }
    while(!mystack.empty()){
        result += mystack.top();
        mystack.pop();
    }
    cout<<result<<endl;
    return 0;
}