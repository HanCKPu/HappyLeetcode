

#include "../../commonHeader.h"


//A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//
//For example, these are arithmetic sequence:
//
//1, 3, 5, 7, 9
//7, 7, 7, 7
//3, -1, -5, -9
//The following sequence is not arithmetic.
//
//1, 1, 2, 5, 7




class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)    return 0;

        int ans = 0;
        vector<int> dp(A.size(), 0);
        for(int i = 2; i < A.size(); ++i) {
            if(A[i] - A[i-1] == A[i-1] - A[i-2]) {
                dp[i] = dp[i-1] + 1;
                ans += dp[i];
            }
        }

        return ans;
    }
};


int main() {
	Solution amazon;

    vector<int> nums {1,2,3,4};
    cout << amazon.numberOfArithmeticSlices(nums) << endl;

	return 0;
}

