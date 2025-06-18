### 1. Two Sum

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector <int> ans;

        for(int i = 0;i < nums.size();i++) {
            mp[nums[i]] = i;
        }

        for(int i = 0;i < nums.size();i++) {
            if(mp[target - nums[i]] && mp[target - nums[i]] != i){
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]]);
                break;
            }
        }

        return ans;
    }
};
```
