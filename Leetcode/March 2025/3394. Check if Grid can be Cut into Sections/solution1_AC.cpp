/**
 * Date: 25-03-2025
 * Complexity: nlogn
 * Time : 652ms 
 * Tag: unoptimized
 * Link: https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/
 */

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector <vector<int>> xse;
        vector <vector<int>> yse;

        int len = rectangles.size();

        for(int i = 0;i <  len;i++) {
            // cout << rectangles[i][1] << endl;
            vector <int> tempx, tempy;

            tempx.push_back(rectangles[i][0]);
            tempx.push_back(rectangles[i][2]);
            tempy.push_back(rectangles[i][1]);
            tempy.push_back(rectangles[i][3]);

            xse.push_back(tempx);
            yse.push_back(tempy);
        }

        sort(xse.begin(), xse.end());
        sort(yse.begin(), yse.end());

        vector <int> ansx, ansy;
        int hx = xse[0][1], hy = yse[0][1];
        for(int i = 0;i < len-1;i++) {
            if(yse[i][1] <= yse[i+1][0]){
                if(i == 0)
                    ansy.push_back(yse[i][1]);
                else if(yse[i][1] >= hy)
                    ansy.push_back(yse[i][1]);
            }

            if(hy < yse[i][1]) hy = yse[i][1];
        }

        for(int i = 0;i < len-1;i++) {
            // cout << "hx :"<<hx << endl;
            if(xse[i][1] <= xse[i+1][0]){
                if(i == 0)
                    ansx.push_back(xse[i][1]);
                else if(xse[i][1] >= hx){
                    ansx.push_back(xse[i][1]);
                    
                }
            }
            if(hx < xse[i][1]) hx = xse[i][1];
        }



        // cout << "====X===="<<endl;
        // for(auto i : xse) {
        //     cout << i[0] << " X "<< i[1]<<endl;
        // }
        // cout << endl;
        // cout << "==== Y ===="<<endl;
        // for(auto i : yse) {
        //     cout << i[0] << " Y "<< i[1]<<endl;
        // }

        
        // cout <<"ANSY"<< endl;
        // for(auto i : ansy) {
        //     cout << i <<endl;
        // }

        // cout <<"ANSX"<< endl;
        // for(auto i : ansx) {
        //     cout << i <<endl;
        // }

        return ansx.size() >= 2 || ansy.size() >= 2;
    }
};