#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> tokens(n);
    for (int i = 0; i < n; ++i) {
        cin >> tokens[i];
    }

    vector<int> dp(k + 1, 99999);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int now = 1; now <= k; ++now) {
            if (now - tokens[i] >= 0) {
                dp[now] = min(dp[now], dp[now - tokens[i]] + 1);
            }
        }
    }

    if (dp[k] == 99999) {
        cout << -1 << endl;
    } else {
        cout << dp[k] << endl;
    }

    return 0;
}