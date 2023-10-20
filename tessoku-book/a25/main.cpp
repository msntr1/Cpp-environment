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
  vector<string> C(H);
  REP (i, H) cin >> C[i];

  vector<vector<ll>> DP(H, vector<ll>(W, 0));
  DP[0][0] = 1;
  REP (i, H+W-1) REP (j, i+1) {
    if (i-j >= H || j >= W) continue;
    if (i-j+1 < H && C[i-j+1][j] == '.') DP[i-j+1][j] += DP[i-j][j]; 
    if (j+1 < W && C[i-j][j+1] == '.') DP[i-j][j+1] += DP[i-j][j]; 
  }
  cout << DP[H-1][W-1] << endl;
}
