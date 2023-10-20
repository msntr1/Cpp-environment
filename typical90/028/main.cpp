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
  ll N;
  cin >> N;
  vector<vector<ll>> imos(1001, vector<ll>(1001, 0));
  REP (i, N) {
    ll lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    imos[lx][ly]++;
    imos[lx][ry]--;
    imos[rx][ly]--;
    imos[rx][ry]++;
  }
  REP (i, 1001) REP (j, 1000) {
    imos[i][j+1] += imos[i][j];
  }
  REP (i, 1001) REP (j, 1000) {
    imos[j+1][i] += imos[j][i];
  }

  vector<ll> ans(N+1, 0);
  REP (i, 1001) REP (j, 1001) {
    ans[imos[i][j]]++;
  }
  REP3 (i, 1, N+1) {
    cout << ans[i] << endl;
  }
}
