#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkFibo(vector<int>& mytemp){
    // bool check = true;
    for(int i = 2; i<mytemp.size(); i++){
        if(mytemp[i-2] + mytemp[i-1] != mytemp[i]){
            return false;
        }
    }
    for(int i = 0; i<mytemp.size(); i++){
        cout<<mytemp[i]<<" ";
    }
    cout<<endl;
    return true;
}
void myrecursion(vector<int>& temp, vector<int>& myinput, int current, int& size){
    if(current == myinput.size()){
        bool check = checkFibo(temp);
        if(check){
            size = size>temp.size() ? size : temp.size();
        }
        return;
    }
    temp.push_back(myinput[current]);
    myrecursion(temp, myinput, current + 1, size);
    temp.pop_back();
    myrecursion(temp, myinput, current + 1, size);
    return;
}

int main(){
    cout<<"All the best!!"<<endl;
    // vector<int> myinput = {1,2,3,4,5,6,7,8};
    vector<int> myinput = {1,3,7,11,12,14,18};
    vector<int> temp;
    int size = 0;
    myrecursion(temp, myinput, 0, size);
    cout<<size<<endl;
    return 0;
}