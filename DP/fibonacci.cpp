#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    // memoization - top down
    int mydp(int n, vector<int> &ref){
        if(n<=1){
            return n;
        }
        else if(n==2){
            return 1;
        }
        if(ref[n] != -1){
            return ref[n];
        }
        ref[n] = mydp(n-1, ref) + mydp(n-2, ref) + mydp(n-3, ref);
        return ref[n];
    };
    // tabulation - bottom up 
    int mydptab(int n){
        // ref[0] = 0;
        // ref[1] = 1;
        // ref[2] = 1;
        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;
        int result = 0;
        for(int i = 3; i<=n; i++){
            result = prev3 + prev2 + prev1;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = result;
            // cout<<ref[i]<<endl;
        }
        return result;
    };
    int tribonacci(int n) {
        // vector<int> ref(n+1, -1);
        // return mydp(n, ref);
        return mydptab(n);
    }
};

int main(){
    int n;
    cout<<"Enter nth fibonacci";
    cin>>n;
    // cout<<endl;
    Solution myprogram;
    int result = myprogram.tribonacci(n);
    cout<<result<<endl;
    return 0;
}