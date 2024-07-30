#include <iostream>
#include <string>
#include <map>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;


//phone book example
//separate chain method
class HashTable{
    private: 
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups];
    public: 
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};
bool HashTable::isEmpty() const{
    int sum{};
    for (int i{}; i<hashGroups; i++){
        sum+=table[i].size();
    }
    if(!sum) return true;
    return false;
}
int HashTable::hashFunction(int key){
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value){
    int hashValue = hashFunction(key);
    auto& cell  = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(;bItr != end(cell);bItr++){
        if(bItr->first == key){
            // fucking whyyyy
        }
    }
}


// Time complexity of Hash maps 

/*
    storing - ordered - O(log N)
    fetching - ordered - O(log N)
    storing - unordered - O(1), O(N)
    fetching - ordered - O(1), O(N)

    use unordered map first, then tle happens => use ordered map 
    O(N) happens because of internal collisions 

    hashing - division, folding, mid square methods of creating map 


*/
int maxOperations(vector<int>& nums, int k) {
    map<int, int> myMap;
    int count = 0;
    for(int i= 0; i<nums.size();i++){
        int res = k - nums[i];
        if(myMap[res] > 0){
            count++;
            if(myMap[res]==1) myMap.erase(res);
            else myMap[res]--;
        }else{
            myMap[res]++;
        }
    }

}
int main(){
    
}