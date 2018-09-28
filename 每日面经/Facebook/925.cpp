

//http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=445335&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26sortid%3D311

#include "../../commonHeader.h"

int read4(char *buf);

class Solution {
public:
	//273
    string numberToWords(int num) {

    }


    //157
    int singleRead(char *buf, int n) {
    	int ans = 0;
    	int size = 4;
    	
    	while(ans < n and size == 4) {
    		size = read4(buf + ans);
    		ans += size;
    	}

    	return min(ans, n);
    }

    //158
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
    	return singleRead(buf, n);
    }


	//就是数字键盘是
	//123
	//456
	//789
	//0
	//然后我们从1开始，假如是0个move，就只有[1]一个解，假如1个move，那就有[16,18]两个解，假如2个move就有[161,167,160,181,183]一共5个解，以此类推
    //其实求的是# of leafs
    int totalSteps(int start, int move) {
    	if(move == 0)	return 1;

    	unordered_map<int, vector<int>> nexts;
    	nexts[1] = vector<int> {6, 8};
    	nexts[2] = vector<int> {7, 9};
    	nexts[3] = vector<int> {4, 8, 0};
    	nexts[4] = vector<int> {3, 9};
    	nexts[5] = vector<int> {};



    	//1. BFS
    	for(int i = 1; i <= move; ++i) {
    		vector<int> currentNums = g(currentNums);
    	}

    	return currentNums.size(); 	

    }

    //370
    //https://leetcode.com/problems/range-addition/description/
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        
    } 


};



int main() {
    Solution Facebook;

	return 0;
}

