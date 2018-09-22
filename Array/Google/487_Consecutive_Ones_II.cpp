

#include "../../commonHeader.h"



//Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
//
//Example 1:
//Input: [1,0,1,1,0]
//Output: 4
//Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
//    After flipping, the maximum number of consecutive 1s is 4.
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty())    return 0;

        int i = 0, j = 0, ans = 0, count = 0;
        for(; j < nums.size(); ++j) {
            if(nums[j] == 0)    count++;

            if(count <= 1)  ans = max(ans, j - i + 1);
            else{
                while(i < j and count > 1)  count -= (nums[i++] == 0);   
            }
        }

        return ans;
    }
};


int main() {
	Solution google;

    vector<int> nums {1,0,1,1,0};
    cout << google.findMaxConsecutiveOnes(nums) << endl;

	return 0;
}

