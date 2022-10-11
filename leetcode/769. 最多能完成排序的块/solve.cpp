class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 1;
        int *dp = new int[n];
        dp[n-1] = arr[n-1];
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = min(arr[i], dp[i+1]);
        }

        int tmp = arr[0];
        for (int i = 1; i < n; ++i) {
            if (tmp <= dp[i]) {
                ++ans;
                tmp = arr[i];
            } else {
                tmp = max(tmp, arr[i]);
            }
        }

        return ans;
    }
};