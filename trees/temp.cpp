#include <iostream>
#include <stack>
#include <string>

using namespace std;
string gcdOfStrings(string str1, string str2) {
        bool check = str1.length()>str2.length();
        if(str1.length() == str2.length()){
            if(str1 == str2){
                return str1;
            }
            else{
                return "";
            }
        }
        else{
            if(!check){
                string temp = str1;
                str1 = str2;
                str2 = temp;
            }
        }
        int j = 0;
        string temp = "";
        int w1 = str1.length();
        int w2 = str2.length();
        for(int i = 0; i<w2;i++){
            while(j<=w1){
                // str2
                j++;
            }
        }
    }

int main(){
    string temp = "Subramani E";
    cout<<temp + temp<<endl;
}