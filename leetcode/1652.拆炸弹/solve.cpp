class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        for (int i = 1; i <= abs(k); ++i) {
            ans[0] += k > 0 ? code[(i + n) % n] : code[(-i + n) % n];
        }
        
        for (int i = 1; i < n; ++i) {
            if (k > 0)
                ans[i] = ans[(i - 1 + n) % n] - code[i] + code[(i + k + n) % n];
            else if (k < 0) {
                ans[i] = ans[(i - 1 + n) % n] + code[(i - 1 + n) % n] - code[(i - 1 + k + n) % n];
            }
        }
        return ans;
    }
};