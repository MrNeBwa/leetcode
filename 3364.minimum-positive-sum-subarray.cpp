/*
 * @lc app=leetcode id=3364 lang=cpp
 *
 * [3364] Minimum Positive Sum Subarray 
 */

// @lc code=start
#include <climits>
#include <cstdint>
#include <vector>
using std::vector;

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;
        for (size_t size = l; size <= r; ++size){
            int currentSumm = 0;
            for (int i = 0; i < size; ++i){
                currentSumm += nums[i];
            }
            if (currentSumm > 0) min_sum = std::min(currentSumm, min_sum);
            for (size_t i = size; i < n; ++i){
                currentSumm += nums[i] - nums[i-size];
                if (currentSumm > 0) min_sum = std::min(currentSumm, min_sum);
            }
        }
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};
// @lc code=end

