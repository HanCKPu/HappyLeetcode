
#include "../../commonHeader.h"

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        if(strings.empty())     return vector<vector<string>>();

        unordered_map<string, vector<string>> m;
        for(const string& str : strings) {
            m[decode(str)].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto& p : m)
            ans.push_back((p.second));

        return ans;
    }

private:
    string decode(const string& that) {
        if(that.empty())    return "";
        string ans = "a";
        int dis = that[0] - 'a';
        for(int i = 1; i < that.size(); ++i) {
            ans += (((that[i] - that[i-1]) + 26) % 26 + ans.back());
        }
        return ans;
    }
};


int main() {
    Solution Google;

    vector<string> strings {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    cout << Google.groupStrings(strings) << endl;

	return 0;
}

