class Solution {
public:
    string reverseString(string s) {
        int l = s.size();
        string ans= "";
        for(int i= l-1; i >= 0; --i) {
            ans += s[i];
        }
        return ans;
    }
};