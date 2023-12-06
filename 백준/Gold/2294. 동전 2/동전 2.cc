#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coin_set;
    for (int i = 0; i < n; ++i) {
        int coin;
        cin >> coin;
        coin_set.push_back(coin);
    }

    sort(coin_set.begin(), coin_set.end());
    coin_set.erase(unique(coin_set.begin(), coin_set.end()), coin_set.end());

    vector<int> cnt(k + 1, -1);
    cnt[0] = 0;

    for (int i = 1; i <= k; ++i) {
        if (i >= coin_set[0]) {
            vector<int> min_cnt;
            for (int coin : coin_set) {
                if (i >= coin) {
                    min_cnt.push_back(cnt[i - coin]);
                }
            }
            sort(min_cnt.begin(), min_cnt.end());
            min_cnt.erase(unique(min_cnt.begin(), min_cnt.end()), min_cnt.end());

            if (min_cnt.back() == -1) {
                continue;
            } else if (min_cnt[0] == -1) {
                cnt[i] = 1 + min_cnt[1];
            } else {
                cnt[i] = 1 + min_cnt[0];
            }
        }
    }

    cout << cnt[k] << endl;

    return 0;
}