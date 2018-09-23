

#include "../../commonHeader.h"


//Input: 3
//Output: 3
//Explanation:
//Intitally, we have one character 'A'.
//In step 1, we use Copy All operation.
//In step 2, we use Paste operation to get 'AA'.
//In step 3, we use Paste operation to get 'AAA'.


class Solution {
public:
    int minSteps(int n) {
        if(n < 0)  return -1;

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                if(i % j != 0)  continue;
                dp[i] = min(dp[i], i / j + dp[j]);
            }
        }

        cout << dp << endl;
        return dp[n];
    }
};


int main() {
	Solution Google;

    Google.minSteps(3);
	return 0;
}

