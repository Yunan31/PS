#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N, Q, x, y;

  cin >> N >> Q;

  vector<int> row;
  int nemo;
  int cur;

  for (int i = 1; i <= N; i++) {
    //각 층의 넴모 수를 받아옴
    cin >> nemo;
    row.push_back(nemo);
  }

  for (int i = 0; i < Q; i++) {
    cin >> x >> y;
    int low = 0, high = N;
    while (low < high) {
      int mid = (low + high) / 2;
      if (row[mid] >= x)
        low = mid + 1;
      else
        high = mid;
    }
    int answer = row[y - 1] - x;
    answer += low - y + 1;
    // cout << "low : " << low << "\n";
    if (x > row[y - 1] || y > low)
      cout << "0\n";
    else
      cout << answer << "\n";
  }

  return 0;
}