/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::vector;
using std::string;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        std::vector<int> rows (std::size(grid), 0);
        std::vector<int> cols (std::size(grid[0]), 0);
        for (size_t i = 0; i < size(rows); ++i){
            for (size_t j = 0; j < size(cols); ++j){
                if (grid[i][j] == 1){
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int answer = 0;
        for (size_t i = 0; i < size(rows); ++i){
            for (size_t j = 0; j < size(cols); ++j){
                if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)){
                    ++answer;
                }
            }
        }
        return answer;
    }
};
// @lc code=end

