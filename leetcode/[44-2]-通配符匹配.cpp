class Solution {
public:
    bool isMatch(string s, string p) {

        int i = 0;
        int j = 0;
        int star = -1;
        int k = 0; // 记录最后一次匹配的位置  + 1

        while (i < s.length()) {
            if (s[i] == p[j] || p[j] == '?') {
                ++i;
                ++j;
                continue;
            }

            if (p[j] == '*') {
                star = j++;
                k = i;
                continue;
            }

            // 如果失配了，回溯到 k + 1，即让 * 再多吞噬一个字符。
            if (star != -1) {
                i = ++k;
                j = star + 1;
                continue;
            }
            return false;
        }

        while (j < p.length() && p[j] == '*') ++j;

        return j == p.length();
    }
};