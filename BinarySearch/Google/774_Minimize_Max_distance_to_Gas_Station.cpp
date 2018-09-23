

#include "../../commonHeader.h"


//On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], where N = stations.length.
//
//Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
//
//Return the smallest possible value of D.
//
//Example:
//
//Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
//Output: 0.500000

//这题和在sorted array中找kth smallest相似


class Solution {
public:
    //s0:   wrong
    //每次找D最大的地方，然后分成两半，这样是错误的。。

    //s1: binary search
    double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            int cnt = 0, n = stations.size();
            for (int i = 0; i < n - 1; ++i) {
                cnt += (stations[i + 1] - stations[i]) / mid;
            }
            cout << "mid = " << mid << endl;
            cout << "cnt = " << cnt << endl << endl;
            if(cnt <= K) 
                right = mid;
            else
                left = mid;
        }
        return left;
    }
};


int main() {
	Solution Google;

    vector<int> stations {1,3,5,7,9};
    int k = 1;
    auto ans = Google.minmaxGasDist(stations, k);
    cout << ans << endl;
	return 0;
}

