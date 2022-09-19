#include <iostream>
#include <map>
#include <string>
using namespace std;
const int N = 3;
const int M = 1005;
int scores[N];
int T;
int main() {
    cin >> T;
    while (T--) {
        int n;
        map<string, int> mp;
        string words[N][M];
        cin >> n;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> words[i][j];
                ++mp[words[i][j]];
            }
        }

        for (int i = 0; i < N; ++i) {
            scores[i] = 0;
        }

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = mp[words[i][j]];
                if (cnt == 3) {
                    continue;
                } else if (cnt == 2) {
                    ++scores[i];
                } else if (cnt == 1) {
                    scores[i] += 3;
                }
            }
        }


        for (int i = 0; i < N; ++i) {
            cout << scores[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
