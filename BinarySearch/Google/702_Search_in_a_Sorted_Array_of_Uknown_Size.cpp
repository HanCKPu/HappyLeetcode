

#include "../../commonHeader.h"


//Input: array = [-1,0,3,5,9,12], target = 9
//Output: 4
//Explanation: 9 exists in nums and its index is 4
//ArrayReader.get(k)
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
    	int l = 0, r = 0;
    	const int times = 2;

    	while(true) {
    		int ele = reader.get(r);
    		if(ele == INT_MAX) {
    			r = l + (r - l) / 2;
    			continue;
    		}

    		if(ele < target) {
    			l = r;
    			r *= times;
    		}
    		else {
    			break;
    		}
    	}

    	while(l <= r) {
    		int mid = l + (r - l) / 2;
    		int ele = reader.get(mid);

    		if(ele == target)		return mid;
    		else if(ele < target)	l = mid + 1;
    		else 					r = mid - 1;
    	}

    	return -1;
    }
};


int main() {
	Solution google;

	return 0;
}

