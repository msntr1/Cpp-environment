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
  vector<vector<ll>> P(H, vector<ll>(W));
  REP (i, H) REP (j, W) {
    cin >> P[i][j];
  }

  ll ans = 0;
  REP (i, (1 << H)) {
    map<ll, ll> M;
    ll cnt = 0;
    REP (j, W) {
      set<ll> S;
      REP (k, H) {
        if (bit(i, k)) S.insert(P[k][j]);
      }
      if (S.size() == 1) {
        M[*S.begin()]++;
        chmax(cnt, M[*S.begin()]);
      }
    }
    ll row = 0;
    REP (j, H) if (bit(i, j)) row++;
    chmax(ans, cnt*row);
  }

  cout << ans << endl;
}
