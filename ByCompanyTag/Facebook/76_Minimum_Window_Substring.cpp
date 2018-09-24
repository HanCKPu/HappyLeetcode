

#include "../../commonHeader.h"

//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty() or s.empty() or t.size() > s.size())   return "";

        int counter = t.size();
        unordered_map<char, int> m;
        for(char c : t)
            m[c]++;

        pair<int,int> ans = make_pair(0, s.size()+1);
        int l = 0, r = 0;
        for(; r < s.size(); ++r) {
            char c= s[r];
            if(m.count(c) == 0)     continue;

            if(m[c]-- > 0)  counter--;
            while(counter <= 0) {
                if(r - l < ans.second - ans.first)  ans = make_pair(l,r);   //update range

                char lChar = s[l];
                if(m.count(lChar) and m[lChar]++ >= 0)  counter++;
                l++;
            }
        }

        return ans.second == s.size()+1 ? "" : s.substr(ans.first, ans.second-ans.first+1);
    }

    //follow up, allow one char difference
    //str1 = acedbg, str2 = xcbe，那么返回cedb
    //solution -> keep a window whose size = target.size(), starting from left to right for one loop    

};


int main() {
    Solution Facebook;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << Facebook.minWindow(s, t) << endl;

	return 0;
}

