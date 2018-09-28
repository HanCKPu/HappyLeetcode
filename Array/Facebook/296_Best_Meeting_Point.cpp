
#include "../../commonHeader.h"

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
       	if(grid.empty() or grid[0].empty())		return 0;

       	vector<int> rows, cols;
       	for(int i = 0; i < grid.size(); ++i) {
       		for(int j = 0; j < grid[0].size(); ++j) {
       			if(grid[i][j] == 1) {
       				rows.push_back(i);
       				cols.push_back(j);
       			}
       		}
       	}

       	sort(rows.begin(), rows.end());
       	sort(cols.begin(), cols.end());

       	int ans = 0;
       	int i = 0, j = rows.size()-1;
       	while(i < j) {
       		ans += (rows[j] - rows[i]);
       		ans += (cols[j] - cols[i]);
       		i++;
       		j--;
       	}

       	return ans;
    }
};


int main() {
    Solution Facebook;

	return 0;
}

