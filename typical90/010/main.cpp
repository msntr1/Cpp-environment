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
  vector<ll> C(N+1), P(N+1);
  REP3 (i, 1, N+1) cin >> C[i] >> P[i];
  ll Q;
  cin >> Q;
  vector<ll> L(Q), R(Q);
  REP (i, Q) cin >> L[i] >> R[i];
  
  vector<ll> A(N+1), B(N+1);
  if (C[1] == 1) A[1] = P[1];
  else B[1] = P[1];
  REP3 (i, 1, N) {
    if (C[i+1] == 1) {
      A[i+1] = A[i] + P[i+1];
      B[i+1] = B[i];
    }
    else {
      B[i+1] = B[i] + P[i+1];
      A[i+1] = A[i];
    }
  }

  REP (i, Q) {
    cout << A[R[i]] - A[L[i]-1] << " ";
    cout << B[R[i]] - B[L[i]-1] << endl;
  }
}