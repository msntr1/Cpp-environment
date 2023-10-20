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


// めぐる式二分探索
ll N, L, K;
vector<ll> A;
// index が条件を満たすかどうか
bool isOK(ll mid) {
  // greedy
  ll last = 0, cnt = 0;
  REP (i, N) {
    if (A[i] - last >= mid) {
      last = A[i];
      cnt++;
    }
    if (cnt == K && L - last >= mid) return true;
  }
  return false;
}
// 汎用的な二分探索のテンプレ
long long binary_search() {
  ll ok = -1; // 
  ll ng = L; // 

  /* ok と ng のどちらが大きいかわからないことを考慮 */
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (isOK(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // 入力
  cin >> N >> L >> K;
  A.resize(N);
  REP (i, N) cin >> A[i];

  cout << binary_search() << endl;
}
