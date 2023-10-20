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
  ll N, M;
  cin >> N >> M;
  vector<ll> A(M+1,0);
  REP3 (i, 1, M+1) REP (j, N) {
    ll x;
    cin >> x;
    A[i] += (x<<j);
  }
  vector<vector<ll>> DP(M+1, vector<ll>((1<<N), infl));
  DP[0][0] = 0;
  REP (i, M) REP (j, (1<<N)) {
    ll to = A[i+1] | j;
    chmin(DP[i+1][j], DP[i][j]);
    chmin(DP[i+1][to], DP[i][j] + 1);
  }

  ll ans = DP[M][(1<<N)-1];
  if (ans == infl) cout << -1 << endl;
  else cout << ans << endl;
}
