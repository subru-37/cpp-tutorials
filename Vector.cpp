#include <iostream>
#include <vector>


using namespace std;
// using namespace vector;

int main(){
    vector<int> n;

    n.assign(9,1);

    cout<<"The contents Are: "<<endl;
    for(int i = 0; i<n.size();i++){
        cout<<n[i]<<endl;
    }

    n.push_back(2);
    int sizeOfN = n.size();
    cout<<"Last Element: "<<n[sizeOfN - 1]<<endl;

    n.pop_back();
    cout<<"Now the contents are: ";
        for(int i = 0; i<n.size();i++){
        cout<<n[i]<<endl;
    }

    n.insert(n.begin(),7);
    cout<<"First ELement is: "<<n[0]<<endl;

    n.clear();
    cout<<"Now the size is: "<<n.size();

    return 0;
}