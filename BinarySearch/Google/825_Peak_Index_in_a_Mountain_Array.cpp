

#include "../../commonHeader.h"
//Input: [0,2,1,0]
//Output: 1

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
  		if(A.empty())		return -1;
  		if(A.size() <= 2)	return max_element(A.begin(), A.end()) - A.begin();

  		int l = 0, r = A.size()-1, mid = 0;
  		while(l <= r) {
  			mid = l + (r - l) / 2;
  			if(A[mid] > A[mid-1] and A[mid] < A[mid+1])	
  				l = mid + 1;
  			else if(A[mid] < A[mid-1] and A[mid] > A[mid+1])
  				r = mid - 1;
  			else
  				return mid;
  		}

  		return -1;
    }
};


int main() {
	Solution Google;

	vector<int> nums {0,1,2,3,2};
	cout << Google.peakIndexInMountainArray(nums) << endl;

	return 0;
}

