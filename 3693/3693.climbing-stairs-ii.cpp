/*
 * @lc app=leetcode id=3693 lang=cpp
 *
 * [3693] Climbing Stairs II
 */

// @lc code=start

#include <vector>
using std::vector;

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector <int> dp (n+1, __INT_MAX__);
        int jump[] = {1,2,3};
        dp[0] = costs[0];
        for (size_t i = 0; i < size(dp); ++i){
            for (const auto& c : jump){
                if (i + c < size(dp)){
                    dp[i+c] = std::min(dp[i+c], dp[i] + costs[i+c]);
                }
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

