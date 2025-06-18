### 121. Best Time to Buy and Sell Stock

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxVal = 0;
        int base = prices[0];
        for(int i = 0;i < prices.size();i++) {
            if(prices[i] < base) {
                base = prices[i];
            }
            maxVal = max(prices[i] - base, maxVal);
        }
        return maxVal;
    }
};
```
