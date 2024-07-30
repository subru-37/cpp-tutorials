#include <iostream>
#include <vector>

using namespace std;

void subsequence(vector<int>& myarray, int index, vector<int>& basearray){
    if(index>=basearray.size()){
        for(auto x: myarray){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    myarray.push_back(basearray[index]);
    subsequence(myarray, index + 1, basearray);  // take
    myarray.pop_back();
    subsequence(myarray, index + 1, basearray); // not take
}

void subsequenceSum(vector<int>& myarray, int index, vector<int>& basearray, int target, int current){
    if(index == myarray.size()){
        // if(current == target ){
            cout<<"Target sum "<<target<<": "<<endl;
            for(auto x: myarray){
                cout<<x<<" ";
            }
            cout<<endl;
            return;
        // }
    }
    myarray.push_back(basearray[index]);
    int mysum = current + basearray[index];
    subsequenceSum(myarray, index + 1, basearray, target, mysum);  // take
    myarray.pop_back();
    mysum = current - basearray[index];
    subsequenceSum(myarray, index + 1, basearray, target, mysum); // not take
}

int main(){
    vector<int> myarray = {3, 1, 2, 5, 6, 4, 5, 9};
    vector<int> temp;
    // int target = 10;
    // int temp = 0;
    // subsequence(temp, 0, myarray);
    subsequenceSum(temp, 0, myarray, 10, 0);

    return 0;
}