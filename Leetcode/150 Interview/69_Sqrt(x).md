### 69. Sqrt(x)

-   Using binary search.

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int high = x;
        int low = 0;

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(mid * mid == x)
                return mid;

            else if(mid * mid < x)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};
```
