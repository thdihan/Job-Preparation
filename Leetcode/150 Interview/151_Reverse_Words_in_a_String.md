### 151. Reverse Words in a String

[Link](https://leetcode.com/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150)

---

Note: Check for more better approach.

---

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string sub = "";
        string ans = "";

        for (int i = s.size() - 1; i >= 0;i--) {
            char c = s[i];
            if(c == ' ' && sub != ""){
                if(ans.size() > 0) ans += " ";
                ans += sub;
                sub = "";
            }
            else if(c != ' '){
                string temp = "";
                temp += c;
                // cout << sub << " "<<temp;
                sub = temp + sub;
            }
        }

        if(sub != "") {
            if(ans.size() > 0) ans += " ";
            ans += sub;
        }


        return ans;
    }
};
```
