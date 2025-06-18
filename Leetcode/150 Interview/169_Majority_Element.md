### 169. Majority Element

[Link]()

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mp;

        for(int i = 0;i < nums.size();i++) {
            mp[nums[i]]++;
        }

        int ans;
        for(auto i: mp) {
            if(i.second > floor(nums.size() / 2)){
                ans =  i.first;
                break;
            }
        }

        return ans;
    }
};
```
