/*
 * @lc app=leetcode id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 */

// @lc code=start
#define ll long long
#include <vector>
using std::vector;
const ll M = 1e9+7;
class Solution {
public:
    int numOfSubarrays(vector<int>& a) {
        int n = a.size(), sum = 0, os = 0, es = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            sum += a[i];
            if(sum%2){
                ans += es+1;
                os++;
            }
            else{
                ans += os;
                es++;
            }
            ans %= M;
        }
        return ans;
    }
};
// @lc code=end

