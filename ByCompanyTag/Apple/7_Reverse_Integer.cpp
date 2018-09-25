

#include "../../commonHeader.h"


class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }

        return (ans < INT_MIN or ans > INT_MAX) ? 0 : ans;
    }
};



int main() {
    Solution Apple;

	return 0;
}

