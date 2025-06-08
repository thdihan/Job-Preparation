## 71. Simplify Path

[https://leetcode.com/problems/simplify-path/description/](https://leetcode.com/problems/simplify-path/description/)

-   Time: `O(n)`

```cpp
class Solution {
    public:
        void processPath (string &path, string &part, deque<string> &dq) {
            if(part == "" || part == ".") {
                part = "";
            }
            else if(part == "..") {
                if(!dq.empty())
                    dq.pop_back();
                part = "";
            }else {
                dq.push_back(part);
                part = "";
            }
        }
        string simplifyPath(string path) {
            deque<string> dq;

            string ans = "";
            string part = "";

            for(int i = 0;i < path.size();i++) {
                if(path[i] == '/') {
                    processPath(path, part, dq);
                }
                else {
                    part += path[i];
                }
            }

            // For the case like /main/.. or /main/new which did't finish with /
            if(part != "") processPath(path, part, dq);

            while(!dq.empty()) {
                ans += "/" + dq.front()  ;
                dq.pop_front();
            }

            if(ans == "") ans = "/";

            return ans;
        }
};
```
