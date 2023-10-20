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
  double T, L, X, Y;
  cin >> T >> L >> X >> Y;
  ll Q;
  cin >> Q;
  vector<ll> E(Q);
  REP (i, Q) cin >> E[i];
  REP (i, Q) {
    double rad = (3.5 - 2*E[i]/T) * M_PI; // ラジアン
    double posY = cos(rad) * L / 2;
    double posZ = sin(rad) * L / 2 + L / 2;
    cout << fixed << setprecision(12) << atan2(posZ, sqrt(X*X+(Y-posY)*(Y-posY))) * 180 / M_PI << endl;
  }
}
