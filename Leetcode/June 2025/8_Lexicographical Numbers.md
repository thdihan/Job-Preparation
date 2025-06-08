## 386. Lexicographical Numbers

Date: 8 June, 2025

Link : [https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2025-06-08](https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2025-06-08)

```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        int cnt = 1;
        vector <int> ans;

        for(int i = 0;i < n;i++) {
            ans.push_back(cnt);

            if(cnt * 10 <= n) {
                cnt = cnt * 10;
            } else {
                while (cnt % 10 == 9 || cnt >= n) {
                    cnt /= 10;
                }

                cnt += 1;
            }
        }
        return ans;
    }


};
```
