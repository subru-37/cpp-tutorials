#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> num;
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    
    for(int i=0; i<n;i++){
        cout<<"Enter element "<<i<<": ";
        int temp;
        cin>>temp;
        num.push_back(temp);
    }

    cout<<"The vector: "<<endl;

    for(auto a=num.begin();a<num.end();a++){
        cout<<*a<<" ";
    }
    return 0;
}