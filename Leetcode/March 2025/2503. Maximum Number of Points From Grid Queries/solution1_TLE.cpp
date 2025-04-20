/**
 * Date: 28-03-2025
 * Complexity: m * n 
 * Time : - 
 * Tag: unoptimized
 * Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/
 * Note: Used floodfill. 
 */



#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int floodfill(vector<vector<int>>& grid, vector<vector<int>>& visited, int q, int x, int y) {
        if(x < 0 || y < 0 || x == grid.size() || y == grid[0].size() || grid[x][y] >= q || visited[x][y] == q) return 0;

        visited[x][y] = q;

        int cnt = 1;

        cnt += floodfill(grid, visited, q, x-1,y);
        cnt += floodfill(grid, visited, q, x+1,y);
        cnt += floodfill(grid, visited, q, x,y+1);
        cnt += floodfill(grid, visited, q, x,y-1);

        return cnt;
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        vector <int> ans; 
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i = 0;i < queries.size();i++) {
            int cnt = floodfill(grid, visited, queries[i], 0,0);

            ans.push_back(cnt);

            // for(auto j: visited) {
            //     for(auto k : j) {
            //         cout << k <<" ";
            //     }
            //     cout << endl;
            // }

            // cout << endl << "ANS : "<<cnt <<endl;;
        }

        return ans;
    }
};