#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v1;
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    
    for(int i=0; i<n;i++){
        cout<<"Enter element "<<i<<": ";
        int temp;
        cin>>temp;
        v1.push_back(temp);
    }
    cout<<"Vector Size is: "<<v1.size()<<endl;
    cout<<"Capacity of vector is: "<<v1.capacity()<<endl;
    cout<<"Max size of vector is: "<<v1.max_size()<<endl;
    v1.resize(30);
    cout<<"Vector Size after resizing is: "<<v1.size()<<endl;
    if(v1.empty() == false){
        cout<<"Vector is not empty"<<endl;
    }else{
        cout<<"Vector is empty"<<endl;
    }
    return 0;
}