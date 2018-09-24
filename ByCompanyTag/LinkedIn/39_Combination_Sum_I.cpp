

#include "../../commonHeader.h"


//Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
//The same repeated number may be chosen from candidates unlimited number of times.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       	if(candidates.empty())		return vector<vector<int>>();

       	sort(candidates.begin(), candidates.end());
       	vector<vector<int>> ans;
       	vector<int> sub;

       	dfs(sub, ans, candidates, target, 0);
       	return ans;
    }

    void dfs(vector<int>& sub, vector<vector<int>>& ans, vector<int>& candidates, int target, int currIdx) {
    	if(target == 0)	{
    		ans.push_back(sub);
    		return;
    	}

    	for(int i = currIdx; i < candidates.size(); ++i) {
    		int val = candidates[i];
    		if(val > target)	return;
    		sub.push_back(val);
    		dfs(sub, ans, candidates, target - val, i);
    		sub.pop_back();
    	}
    }
};


int main() {
    Solution LinkedIn;

    vector<int> nums {2,3,6,7};
    auto ans = LinkedIn.combinationSum(nums, 7);
    cout << ans << endl;

	return 0;
}

