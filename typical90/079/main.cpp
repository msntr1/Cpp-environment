#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
//using mint = modint;
//using mint = modint1000000007;
//using mint = modint998244353;
typedef long long ll;
#define int ll
const ll infl = 1LL << 60;
#define REP(i,n) for (ll i = 0; (i) < (ll)(n); ++ (i))
#define REP3(i,m,n) for (ll i = (m); (i) < (ll)(n); ++ (i))
#define REP_R(i,n) for (ll i = (ll)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i,m,n) for (ll i = (ll)(n) - 1; (i) >= (ll)(m); -- (i))
#define all(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())
#define bit(x,i) (((x)>>(i))&1)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }


signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // 入力
  ll H, W;
  cin >> H >> W;
  vector<vector<ll>> A(H, vector<ll>(W)), B(H, vector<ll>(W)), C(H, vector<ll>(W));
  REP (i, H) REP (j, W) cin >> A[i][j];  
  REP (i, H) REP (j, W) cin >> B[i][j];
  REP (i, H) REP (j, W) {
    C[i][j] = B[i][j] - A[i][j];
  }
  const vector<int> dx{0, 1, 0, 1};
  const vector<int> dy{0, 0, 1, 1};
  ll sum = 0;
  REP (i, H-1) REP (j, W-1) {
    ll d = C[i][j];
    REP (k, 4) {
      C[i+dy[k]][j+dx[k]] -= d;
    }
    sum += abs(d);
  }

  bool ans = true;
  REP (i, H) REP (j, W) if (C[i][j] != 0) ans = false;
  if (ans) {
    cout << "Yes" << endl;
    cout << sum << endl;
  }
  else cout << "No" << endl;
}
