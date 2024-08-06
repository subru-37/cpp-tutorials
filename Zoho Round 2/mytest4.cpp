#include <iostream>

using namespace std;

int main(){
    int n = 16;
    if(n%2==0){
        for(int i = 0; i<n; i++){
            if(i%2 == 0 && i<n/2){
                int j = 0;
                for(j = 0; j<i/2; j++){
                    cout<<"* . ";
                }
                j = j*2;
                for(;j<n/2; j++){
                    cout<<"* ";
                }
                // j = 0;
                for(j = 0;j<n/2 - i; j++){
                    cout<<"* ";
                }
                j = j*2;
                for(j = 0; j<i/2; j++){
                    cout<<". * ";
                }
            }else if(i%2 == 1 && i<n/2){
                int j = 0;
                for(j = 0; j<i/2; j++){
                    cout<<"* . ";
                }
                j = j*2;
                for(;j<n/2; j++){
                    cout<<". ";
                }
                for(j = 0;j<n/2 - i; j++){
                    cout<<". ";
                }
                j = j*2;
                for(j = 0; j<i/2; j++){
                    cout<<"* . ";
                }

            }else if(i%2 == 0 && i>=n/2){
                int j = 0;
                for(j = 0; j<(n-i)/2; j++){
                    cout<<"* . ";
                }
                j = j*2;
                for(;j<n/2; j++){
                    cout<<". ";
                }
            }else if(i%2 == 1 && i>=n/2){
                int j = 0;
                for(j = 0; j<(n-i)/2; j++){
                    cout<<"* . ";
                }
                j = j*2;
                for(;j<n/2; j++){
                    cout<<"* ";
                }  
            }
            cout<<endl;
        }
    }
    
    return 0;
}