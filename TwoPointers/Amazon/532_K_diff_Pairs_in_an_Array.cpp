
#include "../../commonHeader.h"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)   return 0;

        unordered_map<int,int> m;
        for(int n : nums)   m[n]++;

        int ans = 0;
        for(auto& p : m) {
            if(k == 0 and p.second >= 2)    ans++;
            else if(k > 0 and m.count(p.first + k)) ans++;
        }

        return ans;
    }
};


int main() {
    Solution Amazon;

	return 0;
}

