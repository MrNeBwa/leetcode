/*
 * @lc app=leetcode id=3420 lang=cpp
 *
 * [3420] Count Non-Decreasing Subarrays After K Operations
 */

// @lc code=start
#include <vector>
#define ll long long
using std::vector;
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        //TODO:
        /*
        Create matrix n, n
        1. Calculate the value of adding each number
        2. Sum and add if possible
        
        7 8 0 2

        0 0 8 6 -- prefix array

        7 (0 operation)

        7 8 (0 operation)

        7 8 0 (8 operation)

        7 8 0 2 (8 + 6 operations)

        0 2 (0 operation)

        */
       size_t n = nums.size();
       std::vector<std::vector<int>> matrix (n);
       for (size_t i = 0; i < n; ++i){
        std::vector<int> prefix (n, 0);
        for (auto j = i + 1; j < n; ++j){
            int sum = nums[j-1] + prefix[j-1] - nums[j];
            prefix[j] = (sum > 0) ? sum : 0;  
        }
        matrix[i] = prefix;
       }
        ll ans = 0;
        for (size_t i = 0; i < n; ++i){
            int summ = 0;
            for (const auto& c : matrix[i]){
                summ++;
                if (summ <= k) ans ++;
            }
        }
        return ans;
    }
};
// @lc code=end

