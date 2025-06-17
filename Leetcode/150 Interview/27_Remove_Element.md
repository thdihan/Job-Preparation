### 27. Remove Element

[Link]()

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector <int> ans, rem;

        for(int i = 0;i < nums.size();i++) {
            if(nums[i] != val)
                ans.push_back(nums[i]);
            else
                rem.push_back(nums[i]);
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
