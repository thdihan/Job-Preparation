### 14. Longest Common Prefix

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string sub = "";
        int end = strs[0].size();
        for(auto c: strs[0]) {
            sub += c;
        }

        for(int i = 1;i < strs.size();i++) {
            int l = strs[i].size();
            end = min(end, l);

            for(int j = 0;j < strs[i].size();j++) {
                if(j == end)   break;
                if(sub[j] != strs[i][j]) {
                    end = min(end, j);
                    break;
                }
            }
        }

        return strs[0].substr(0, end);
    }
};
```
