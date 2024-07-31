#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> mydp(size, -1);
        mydp[0] = nums[0];
        if(size > 1){
            mydp[1] = nums[1];
            for(int i = 2; i<size; i++){
                mydp[i] = mydp[i-2] + nums[i];
            }
            return max(mydp[size - 1], mydp[size-2]);
        }else{
            return nums[0];
        }
    }
};