

#include "../../commonHeader.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if(nums.empty())	return -1;

    	int l = 0, r = nums.size()-1, mid = 0;
    	while(l <= r) {
    		mid = l + (r - l) / 2;
    		if(nums[mid] == target)		return mid;

    		if(nums[l] <)
    	}        
    }


};



int main() {
    Solution Apple;

	return 0;
}

