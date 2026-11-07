/*
 * @lc app=leetcode id=1882 lang=cpp
 *
 * [1882] Process Tasks Using Servers
 */

// @lc code=start
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using F = pair<int,int>;             
        using B = tuple<long long,int,int>;   

        priority_queue<F, vector<F>, greater<F>> freeQ;
        priority_queue<B, vector<B>, greater<B>> busyQ;

        for (int i = 0; i < (int)servers.size(); ++i)
            freeQ.push({servers[i], i});

        vector<int> ans(tasks.size());
        long long t = 0;

        for (int j = 0; j < (int)tasks.size(); ++j) {
            t = max<long long>(t, j);
            if (freeQ.empty())
                t = max(t, get<0>(busyQ.top()));
            while (!busyQ.empty() && get<0>(busyQ.top()) <= t) {
                auto [ft, w, id] = busyQ.top(); busyQ.pop();
                freeQ.push({w, id});
            }

            auto [w, id] = freeQ.top(); freeQ.pop();
            ans[j] = id;
            busyQ.push({t + tasks[j], w, id});
        }
        return ans;
    }
};
// @lc code=end

