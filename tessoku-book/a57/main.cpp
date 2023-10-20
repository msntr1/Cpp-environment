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
  ll N, Q;
  cin >> N >> Q;
  vector<vector<ll>> DP(30, vector<ll>(N+1, 0));

  REP3 (i, 1, N+1) {
    ll a;
    cin >> a;
    DP[0][i] = a;
  }

  REP3 (i, 1, 30) REP3 (j, 1, N+1) {
    DP[i][j] = DP[i-1][DP[i-1][j]];
  }

  REP (i, Q) {
    ll x, y;
    cin >> x >> y;

    ll cnt = 0;
    ll pos = x;
    while(y) {
      if (y&1) pos = DP[cnt][pos];
      cnt++;
      y /= 2;
    }

    cout << pos << endl;
  }
}
