#include <iostream>
#include <vector>
class Solution{
public:
    std::vector<int> assignTasks(std::vector<int>& servers, std::vector<int>& tasks) {
       return {}; 
    }
};

/*
[3,3,2]
[1,2,3,2,1,2]
[5,1,4,3,2]
[2,1,2,4,5,2,1]
*/
int main(){
    Solution s;
    std::vector <int> in1 {3,3,2};
    std::vector<int> in12 {1,2,3,2,1,2};
    std::vector<int> in2 {5,1,4,3,2};
    std::vector<int> in22 {2,1,2,4,5,2,1};
    std::vector<int> out1 {2,2,0,2,1,2};
    std::vector<int> out2 {1,4,1,4,1,3,2};

    std::cout << ((s.assignTasks(in1, in12) == out1) ? "First passed" : "First failed") << '\n';
    std::cout << ((s.assignTasks(in2, in22) == out2) ? "Second passed" : "Second failed") << '\n';

    return 0;
}