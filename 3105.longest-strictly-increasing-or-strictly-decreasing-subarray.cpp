/*
 * @lc app=leetcode id=3105 lang=cpp
 *
 * [3105] Longest Strictly Increasing or Strictly Decreasing Subarray
 */

// @lc code=start
#include <vector>
using std::vector;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max = 1, inc = 1, dec = 1;
        for (size_t i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i-1]){
                inc++;
                dec = 1;
            }
            else if (nums[i] < nums[i-1]){
                dec++;
                inc = 1;
            }
            else {
                dec = 1;
                inc = 1;
            }
            max = std::max (dec, inc);
        }
        return max;
    }
};
// @lc code=end

