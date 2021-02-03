#include <bits/stdc++.h>

// Time complexity O(NlogN)
using namespace std;
// Maximum size of the skills array
const int N = 1e6 + 5;

// s is the skills array
int s[N];
// prefix sum array of the skills array
long long sum[N];

// tc: test case number
void solve(int tc) {
  long long ans = 1e18;
  int n, p;
  scanf("%d %d", &n, &p);
  for (int i = 0; i < n; ++i)
    // assign items to the skills array
    scanf("%d", s+i);

  //sort the skills array
  sort(s, s+n);
  sum[0] = 0;
  //Make the prefix sum array
  for (int i = 0; i < n; ++i) {
    sum[i+1] = sum[i] + s[i];
  }
  for (int i = p; i <= n; ++i) {
    // Below is a sliding window step
    // eg. if p=2 and s=[1,3,5,7] after sorting then we would have a sliding window of size p=2
    // first iteration would consider [1,3] and give cur = 2
    // second iteration would consider [3,5] and give cur = 2 and so on..
    long long cur = 1LL * s[i-1] * p - sum[i] + sum[i-p];
    ans = min(ans, cur);
  }
  printf("Case #%d: %lld\n", tc, ans);
}

int main() {
  time_t startt = clock();
// tt : Number of test cases
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}