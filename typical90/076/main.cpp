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
  vector<ll> A(N);
  REP (i, N) cin >> A[i];
  ll sum = 0;
  REP (i, N) sum += A[i];
  sum /= 10;
  vector<ll> D(2*N+1);
  REP3 (i, 1, 2*N+1) {
    ll j = (i-1) % N;
    D[i] = D[i-1]+A[j];
  }
  ll pos = 0;
  REP3 (l, 1, N+1) {
    REP3 (r, max(l, pos), N+l) {
      if (D[r]-D[l-1] == sum) {
        cout << "Yes" << endl;
        return 0;
      }
      if (D[r]-D[l-1] > sum) {
        pos = r;
        break;
      }
    }
  }
  cout << "No" << endl;
}
