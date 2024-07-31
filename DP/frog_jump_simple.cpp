// this is not the leetcode problem called frog jump, this is from striver's playlist
// energy lost in a jump from i+1 th or i+2 th stair is given by the difference of  | stones[i] - stones[i+1] | (or i+2)
// find minimum energy to reach the end of the river

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    // basic recursion
    int myenergy(int index, vector<int>& energies){
        if(index == 0){
            return 0;
        }
        int left = myenergy(index - 1, energies) + abs(energies[index] - energies[index - 1]);
        int right = __INT_MAX__;
        if(index>1){
            right = myenergy(index - 2, energies) + abs(energies[index] - energies[index - 2]);
        }
        return min(left, right);
        
    };

    // memoization + recursion

    //myenergy2(index - 1, energies, mydp) will return the energy required to reach index - 1 from 0
    //myenergy2(index - 2, energies, mydp) will return the energy required to reach index - 2 from 0
    int myenergy2(int index, vector<int>& energies, vector<int> mydp){
        if(index == 0){
            return 0;
        }
        if(mydp[index] != -1){
            return mydp[index];
        }
        int left = myenergy2(index - 1, energies, mydp) + abs(energies[index] - energies[index - 1]);
        int right = __INT_MAX__;
        if(index>1){
            right = myenergy2(index - 2, energies, mydp) + abs(energies[index] - energies[index - 2]);
        }
        return mydp[index] = min(left, right);
    }

    // bottom up approach without recursion and with tabulation
    int myenergy3(vector<int> energies, int n){
        vector<int> mydp(n + 1, -1);
        mydp[n-1] = 0;
        mydp[0] = 0; //base case of recursion as starting point of dp
        int oneJump, twoJump;
        for(int i = 1; i<n; i++){
            oneJump = mydp[i-1] + abs(energies[i-1] - energies[i]);
            if(i>1){
                twoJump = mydp[i-2] + abs(energies[i-2] - energies[i]);
            }
            mydp[i] = min(oneJump, twoJump);
        }
        return mydp[n-1];
    }

    // bottom up approach solution with O(1)
    int myenergy4(vector<int> energies, int n){
        // vector<int> mydp(n + 1, -1);
        int mydp1 = 0;
        int mydp2 = 0;
        int current = 0;
        int oneJump, twoJump;
        for(int i = 1; i<n; i++){
            oneJump = mydp1 + abs(energies[i-1] - energies[i]);
            if(i>1){
                twoJump = mydp2 + abs(energies[i-2] - energies[i]);
            }
            current = min(oneJump, twoJump);
            mydp2 = mydp1;
            mydp1 = current;
        }
        return mydp1;
    }
    //handler
    void canCross(vector<int>& stones) {
        vector<int> mydp(stones.size() + 1, -1);
        cout<<myenergy2(stones.size() - 1, stones, mydp)<<endl;
    }
};

int main(){
    int n;
    cout<<"Enter number of energy levels: ";
    cin>>n;
    vector<int> mystones;
    int temp;
    for(int i = 0; i<n; i++){
        cout<<"Enter energy at "<<i<<": ";
        cin>>temp;
        mystones.push_back(temp);
    } 
    Solution mysolution;
    mysolution.canCross(mystones);

}