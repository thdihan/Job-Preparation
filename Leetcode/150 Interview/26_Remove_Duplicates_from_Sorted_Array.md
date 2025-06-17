### 26. Remove Duplicates from Sorted Array

[Link]()

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector <int> ans, rem;
        map<int, int> chk;

        for(int i = 0;i < nums.size();i++) {
            if(chk[nums[i]] == 0) {
                ans.push_back(nums[i]);
                chk[nums[i]]++;
            }
            else {
                rem.push_back(nums[i]);
            }
        }

        int i;
        for(i = 0;i < ans.size();i++) {
            nums[i] = ans[i];
        }
        for(int j = 0;j + i < nums.size();j++) {
            nums[j+i] = rem[j];
        }

        return ans.size();
    }
};
```
