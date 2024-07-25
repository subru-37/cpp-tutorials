#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
//keys in ascending order!!!
// .count in O(1) !!!!
// int main(){
//     map<string, string> myDict;
//     myDict.insert(pair<string, string>("apple", "Apple")); 
//     myDict.insert(pair<string, string>("orange", "orange, orange"));
//     myDict.insert(pair<string, string>("banana", "Banana")); 
//     myDict["orange"] = "orange";
//     for(auto pair: myDict){
//         cout<<pair.first<<" "<<pair.second<<endl;
//     } 
//     cout<<myDict.size()<<endl;
//     return 0;
// }

map<string, vector<string>> mapErase(map<string, vector<string>> mp, string x){
    auto it = mp.find(x);
    if(it!=mp.end()){
        mp.erase(it);
        cout<<x<<" erased"<<endl;
    }
    else{
        cout<<"Not FOund"<<endl;
    }
    return mp;
}
//pokedex
int main(){
    std::map<string, vector<string>> pokedex;
    vector<string> pikachuAttacks {"Thunder Shock", "Tail Whip", "Quick Attack"};
    vector<string> charmanderAttacks {"Flame Thrower", "Scary Face"};
    vector<string> chickoritaAttacks {"Razor Leaf", "Poison Powder"};
    // pokedex.find
    pokedex.insert(pair<string, vector<string>>("pikachu", pikachuAttacks));
    pokedex.insert(pair<string, vector<string>>("charmander", charmanderAttacks));
    pokedex.insert(pair<string, vector<string>>("chickorita", chickoritaAttacks));

    for (auto pair:pokedex){
        cout<<pair.first<<": ";
        for (auto attack: pair.second){
            cout<<attack<<", ";
        }
        cout<<endl;
    }
    pokedex = mapErase(pokedex, "pikachu");
        for (auto pair:pokedex){
        cout<<pair.first<<": ";
        for (auto attack: pair.second){
            cout<<attack<<", ";
        }
        cout<<endl;
    }
}