#include <iostream>
#include <vector>

using namespace std;
// can't perform two similar tasks on consecutive days
// array of arrays where each array is the points awarded for 3 activities on that day
// get max points possible

class Solution{
    //normal recursion solution
    int recursion1(int dayLeft, int lastTask, vector<vector<int>> mypoints){
        int maxi = 0;
        if(dayLeft == 0){
            for(int i = 0; i<3; i++){
                if( i != lastTask){
                    maxi = std::max(maxi, mypoints[0][i]);
                }
            }
            return maxi;
        }
        int points = 0;
        for(int i = 0; i<3; i++){
            if( i != lastTask){
                // maxi = std::max(maxi, mypoints[0][i]);
                points = mypoints[lastTask][i] + recursion1(dayLeft - 1, i, mypoints);
                maxi = std::max(maxi, points);
            }
        }
        return maxi;

    }

    //dynamic 2d programming with recursion 
    // Time complexity O(N x 4) x 3
    // Space complexity O(N) + O(N x 4)
    int recursion2(int dayLeft, int lastTask, vector<vector<int>>& mypoints, vector<vector<int>>& my2dp){
        int maxi = 0;
        if(dayLeft == 0){
            for(int i = 0; i<3; i++){
                if( i != lastTask){
                    maxi = std::max(maxi, mypoints[0][i]);
                }
            }
            return maxi;
        }
        if(my2dp[dayLeft][lastTask] != -1){
            return my2dp[dayLeft][lastTask];
        }
        int points = 0;
        for(int i = 0; i<3; i++){
            if( i != lastTask){
                // maxi = std::max(maxi, mypoints[0][i]);
                points = mypoints[lastTask][i] + recursion1(dayLeft - 1, i, mypoints);
                maxi = std::max(maxi, points);
            }
        }
        return my2dp[dayLeft][lastTask] = maxi;

    }


    // tabulation method 
    // bottom up 
    int efficient(vector<vector<int>>& points){
        
    }
    int ninjaTraining(int n, vector<vector<int>>& points){
        vector<vector<int>> my2dp(n, vector<int>(4,-1));

    }

};

int main(){

}