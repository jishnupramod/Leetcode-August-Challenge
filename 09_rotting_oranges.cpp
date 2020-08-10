/*
In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
*/


class Solution {
private:
    bool allRotten(vector<vector<int>> g, int n, int m) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j)
                if (g[i][j] == 1)
                    return false;
        }
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size(), mts = 0, genPop = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    ++genPop;
                }
            }
        }
        while (!q.empty()) {
            if (genPop == 0) {
                ++mts;
                genPop = q.size();
            }
            pair<int, int> p = q.front();
            q.pop();
            --genPop;
            grid[p.first][p.second] = 0;
            if (p.first+1 < n and grid[p.first+1][p.second] == 1) {
                q.push(make_pair(p.first+1, p.second));
                grid[p.first+1][p.second] = 0;
            }
            if (p.first-1 >= 0 and grid[p.first-1][p.second] == 1) {
                q.push(make_pair(p.first-1, p.second));
                grid[p.first-1][p.second] = 0;
            }
            if (p.second+1 < m and grid[p.first][p.second+1] == 1) {
                q.push(make_pair(p.first, p.second+1));
                grid[p.first][p.second+1] = 0;
            }
            if (p.second-1 >= 0 and grid[p.first][p.second-1] == 1) {
                q.push(make_pair(p.first, p.second-1));
                grid[p.first][p.second-1] = 0;
            }
        }
        if (allRotten(grid, n, m))
            return mts;
        return -1;
    }
};