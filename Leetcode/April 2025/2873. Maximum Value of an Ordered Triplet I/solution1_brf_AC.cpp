/**
 * Date: 2-04-2025
 * Complexity: n ^ 3 
 * Time : - 
 * Tag: unoptimized
 * Difficulty : Easy
 * Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description
 * Note: 3 loops here. Can be optimized with greedy solution and prefix sum.
 */
#include <bits/stdc++.h>

using namespace std;

 class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long  ans = 0;
        for(int i = 0;i < nums.size() - 2;i++) {
            for(int j = i + 1;j < nums.size() - 1;j++) {
                for(int k = j + 1;k < nums.size();k++) {
                    long long temp = (long long)(nums[i] - nums[j]) * nums[k];
                    ans = max(temp, ans);
                }
            }
        }

        return ans;
    }
};