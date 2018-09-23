

#include "../../commonHeader.h"



//In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.  If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.
//
//Now, say our starting node is eventually safe if and only if we must eventually walk to a terminal node.  More specifically, there exists a natural number K so that for any choice of where to walk, we must have stopped at a terminal node in less than K steps.
//
//Which nodes are eventually safe?  Return them as an array in sorted order.
//
//The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.  The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.
//
//Example:
//Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
//Output: [2,4,5,6]
//Here is a diagram of the above graph.

//相当于在图中查环, use typological sorting
//time: O(N+E)  -- node + edges
//space: O(N)


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        if(graph.empty())   return vector<int>();
        const int n = graph.size();    

        vector<int> stats(n, 0);
        for(int i = 0; i < n; ++i) {
            dfs(i, graph, stats);
        }

        vector<int> ans;
        for(int i = 0; i < stats.size(); ++i) {
            if(stats[i] == 2)   ans.push_back(i);
        }

        return ans;
    }

    //0: unvisited, 1: visiting, 2: visited
    bool dfs(int index, vector<vector<int>>& graph, vector<int>& stats) {
        if(stats[index] != 0)
            return stats[index] == 2;

        stats[index] = 1;
        for(const int next : graph[index]) {
            if(dfs(next, graph, stats) == false)    return false;
        }
        stats[index] = 2;

        return true;
    }
};


int main() {
	Solution Google;

    vector<vector<int>> graph {
        {1,2},
        {2,3},
        {5,},
        {0},
        {5},
        {},
        {}
    };

    auto ans = Google.eventualSafeNodes(graph);
    cout << ans << endl;

	return 0;
}

