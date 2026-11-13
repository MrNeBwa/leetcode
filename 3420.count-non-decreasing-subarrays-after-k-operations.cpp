/*
 * @lc app=leetcode id=3420 lang=cpp
 *
 * [3420] Count Non-Decreasing Subarrays After K Operations
 */

// @lc code=start
#include <vector>
#define ll long long
using std::vector;
#include <deque>
#include <vector>

class Solution {
public:
    long long countNonDecreasingSubarrays(std::vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        std::deque<int> dq;

        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int idx = dq.front();
                dq.pop_front();
                int next_idx = dq.empty() ? r + 1 : dq.front();
                cost += 1LL * (next_idx - idx) * (nums[l] - nums[idx]);
            }
            dq.push_front(l);
            while (cost > k) {
                cost -= nums[dq.back()] - nums[r];
                if (dq.back() == r) {
                    dq.pop_back();
                }
                --r;
            }
            ans += (r - l + 1);
        }

        return ans;
    }
};
// @lc code=end

