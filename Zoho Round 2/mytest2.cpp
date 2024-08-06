#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n = 9;
    int i = 0;
    int j = 0;
    int mysum = 0;
    int check = 0;
    while(j<=n){
        mysum += j;
        while(mysum>n){
            i++;
            mysum -= i;
        }
        if(mysum == n){
            check++;
            for(int k = i + 1; k<=j; k++){
                cout<<k<<" ";
            }
            cout<<endl;
        }
        j++;
    }
    cout<<check<<endl;
    return 0;
}