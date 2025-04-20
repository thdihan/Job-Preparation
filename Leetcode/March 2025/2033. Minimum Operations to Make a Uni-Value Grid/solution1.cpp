/**
 * Date: 26-03-2025
 * Complexity: m * n * log(n)
 * Time : 979 ms 
 * Tag: unoptimized
 * Link: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/
 * Note: Median approach. Please check prefix sum and two pointer approach. 
 */



#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector <int> val;
        
        int m = grid.size();
        int n = grid[0].size();

        if(m == 1 && n == 1) return 0;

        int rem = grid[0][0] % x;
 
        for(auto i: grid) {
            for(auto j: i) {
                if(j % x != rem) {
                    return -1;
                }
                val.push_back(j);
            }
        }

        sort(val.begin(), val.end());
        int ne = val[val.size() / 2];
        

        int cnt = 0;
        for(auto i: val) {

            cnt += ((max(i, ne) - min(i, ne)) / x);
        }

        return cnt;

    }

};