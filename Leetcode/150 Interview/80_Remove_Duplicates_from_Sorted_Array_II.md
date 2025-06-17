### 80. Remove Duplicates from Sorted Array II

[Link]()

---

## Note: Search for more better approach.

---

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int, int> chk;
        int k = 0;
        int index = -1;
        for (int i = 0;i < n;i++) {
            chk[nums[i]]++;
            if(chk[nums[i]] == 3 && index == -1)
                index = i;
            if(chk[nums[i]] <= 2  && index != -1 ) {
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                index++;
            }

            // if(chk[nums[i]] >= 2) k++;
        }

        for(auto i: chk) {
            cout << i.first << " "<<i.second<<endl;
            k += (i.second <= 2 ? i.second : 2);
        }
        // cout << k << endl;

        return k;
    }
};
```
