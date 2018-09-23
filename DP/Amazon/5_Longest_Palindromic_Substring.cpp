

#include "../../commonHeader.h"


//Input: "babad"
//Output: "bab"
//Note: "aba" is also a valid answer.




class Solution {
public:
    //S1: From center to two slides
    string longestPalindrome(string s) {
        if(s.empty())   return "";

        pair<int,int> range = make_pair(0,0);
        pair<int,int> longest = make_pair(0,0);
        int l = 0, r = 0;
        for(int center = 0; center < s.size(); ++center) {
            vector<pair<int,int>> nexts {
                make_pair(center, center+1),
                make_pair(center, center),
            };

            for(const auto& next : nexts) {
                range = checkRange(s, next.first, next.second);
                if(range.second - range.first > longest.second - longest.first)
                    longest = range;
            }
        }

        return s.substr(longest.first, longest.second - longest.first + 1);
    }

    pair<int,int> checkRange(const string& s, int l, int r) {
        if(l < 0 or r >= s.size() or s[l] != s[r])  return make_pair(0,0);  //invalid input

        while(l-1 >= 0 and r+1 < s.size() and s[l-1] == s[r+1]) {
            l--;
            r++;
        }

        return make_pair(l, r);
    }
}; 


int main() {
	Solution Amazon;

    auto ans = Amazon.longestPalindrome("babad");
    cout << ans << endl;

	return 0;
}

