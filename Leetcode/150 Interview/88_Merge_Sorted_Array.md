### 88. Merge Sorted Array

[Link]()

```cpp
// Two pointer approach.
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m - 1;
        int n2 = n - 1;
        int i = n + m - 1;
        while(n1 >=0 && n2 >= 0) {
            if(nums1[n1] > nums2[n2]) {
                // cout << "PUSH : "<<nums1[n1] << endl;
                nums1[i] = nums1[n1];
                n1--;
            }  else {
                // cout << "PUSH : "<<nums2[n2] << endl;
                nums1[i] = nums2[n2];
                n2--;
            }
            i--;
        }

        if(n2 >= 0) {
            for(int i = 0;i <= n2;i++) {
                // cout << "PUSH : "<<nums2[i] << endl;
                nums1[i] = nums2[i];
            }
        }
        // for(auto i: nums1)
        //     cout << i << " ";
    }
};
```
