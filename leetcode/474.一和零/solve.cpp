class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int nums = strs.size();
        for (int i = 0; i < nums; ++i) {
            int zeros = 0, ones = 0;
            for (auto &c : strs[i]) {
                if (c == '0') {
                    ++zeros;
                } else if (c == '1') {
                    ++ones;
                }
            }

            for (int j = m; j >= zeros; --j) {
                for (int k = n; k >= ones; --k) {
                    dp[j][k] = max(dp[j][k], dp[j-zeros][k-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
private:
    int dp[105][105];
};