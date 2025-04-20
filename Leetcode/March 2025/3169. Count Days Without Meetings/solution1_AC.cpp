/**
 * Date: 24-03-2025
 * Complexity: n^2
 * Time : 2327ms 
 * Tag: unoptimized
 * Link: https://leetcode.com/problems/count-days-without-meetings/description
 */

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int ans = 0;
        for(int i = 0;i < meetings.size();i++) {
            int st = meetings[i][0];
            int nd = meetings[i][1];
            cout << "BASE : "<< st <<" "<<nd<<endl;
            if(i != meetings.size() - 1){
                for(int j = i+1; j < meetings.size();j++) {
                    cout << "CHECK : "<< meetings[j][0] <<" "<<meetings[j][1]<<endl;
                    if(nd >= meetings[j][0] ){
                        if(meetings[j][1] >= nd) {
                            nd = meetings[j][1];
                            cout << "NEW ND "<<nd <<" new i"<<i<<endl;
                        }
                            i++;
                    }
                    else 
                        break;
                }
            }

            ans += (nd - st + 1);
        }

        cout << ans <<endl;
        return days - ans;
    }
};