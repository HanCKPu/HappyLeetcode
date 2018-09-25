

#include "../../commonHeader.h"


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())   return 0;

        unordered_map<char,int> m;
        int slow = 0, fast = 0, ans = 0;
        for(; fast < s.size(); ++fast) {
            char c = s[fast];
            if(m.count(c) == 0) {
                m[c] = fast;
                ans = max(ans, fast - slow + 1);
            }
            else {
                while(slow <= m[c]) {
                    m.erase(s[slow++]);
                }
                m[c] = fast;
            }
        }

        return ans;
    }
};



int main() {
    Solution Apple;

    string s = "tmmzuxt";
    cout << Apple.lengthOfLongestSubstring(s) << endl;

	return 0;
}

