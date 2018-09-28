

#include "../../commonHeader.h"

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if(nums.empty())    return 0;
        const int n = nums.size();
        vector<bool> visited(n, false);
        int ans = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(visited[i] == false)
                dfs(ans, 1, i, visited, nums);
        }

        return ans;
    }

    void dfs(int& ans, int counter, int index, vector<bool>& visited, vector<int>& nums) {
        visited[index] = true;

        int next = nums[index];

        if(visited[next]) {
            ans = max(ans, counter);
            return;
        }

        dfs(ans, counter+1, next, visited, nums);
    }
};



int main() {
    Solution Apple;

    vector<int> nums {5,4,0,3,1,6,2};
    cout << Apple.arrayNesting(nums) << endl;

	return 0;
}

