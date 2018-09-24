

#include "../../commonHeader.h"

//Given a list of daily temperatures, produce a list that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
//
//For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
//
//Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].


class Solution {
public:

    //s1: stack
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty())    return vector<int>();

        stack<pair<int,int>> s;
        vector<int> ans(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); ++i) {
            const int t = temperatures[i];
            if(s.empty() or s.top().first > t)    s.push(make_pair(t, i));
            else {
                while(not s.empty() and t > s.top().first) {
                    ans[s.top().second] = i - s.top().second;
                    s.pop();
                }
                s.push(make_pair(t,i));
            }
        }
        return ans;
    }

    //s2
    //for each day from end to start, record the next day of temperature t for all t in [30, 100]
    //for each day from n-1 to 0; for all temperature higher than temp[i], find the earliest
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> waits(n, 0);
        vector<int> next(101, INT_MAX); // next day with with certain temperature.
        for (int i = n - 1; i >= 0; i--) {
            int earliest = INT_MAX;
            for (int t = temps[i] + 1; t <= 100; t++) {
                earliest = min(earliest, next[t]);
            }
            if (earliest != INT_MAX) waits[i] = earliest - i;
            next[temps[i]] = i;
        }
        return waits;
    } 
};


int main() {

    Solution Amazon;
    vector<int> nums {1,2,3,2,1};
    auto ans = Amazon.dailyTemperatures(nums);
    cout << ans << endl;

	return 0;
}

