#include <iostream>
using namespace std;
const int N = 105;
int T;
int n;
int k;
int nums[N];
int main(void) {
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        int ans = 0;
        for (int i = 0; i < k; ++i) {
            if (nums[i] > k) {
                ++ans;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

