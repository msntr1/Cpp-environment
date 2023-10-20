#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint;
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
  ll mod = 46;
  mint::set_mod(mod);
  ll N;
  cin >> N;
  vector<mint> A(N), B(N), C(N);
  REP (i, N) {
    ll x;
    cin >> x;
    A[i] = x;
  }
  REP (i, N) {
    ll x;
    cin >> x;
    B[i] = x;
  }
  REP (i, N) {
    ll x;
    cin >> x;
    C[i] = x;
  }
  vector<ll> D(46), E(46), F(46);
  REP (i, N) {
    D[A[i].val()]++;
    E[B[i].val()]++;
    F[C[i].val()]++;
  }
  ll ans = 0;
  REP (i, 46) REP (j, 46) REP (k, 46) {
    if ((i + j + k) % 46 == 0) ans += D[i] * E[j] * F[k];
  }
  cout << ans << endl;
}
