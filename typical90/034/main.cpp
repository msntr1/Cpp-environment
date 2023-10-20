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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP (i, N) cin >> A[i];

  ll ans;
  map<ll, ll> M;
  ll l = 0, r = 0;
  M[A[0]]++;
  ans = 1;
  while (true) {
    if (M.size() <= K) {
      chmax(ans, r-l+1);
      r++;
      if (r < N) M[A[r]]++;
      else break;
    }
    else {
      M[A[l]]--;
      if (M[A[l]] == 0) M.erase(A[l]);
      l++;
    }
  }

  cout << ans << endl;
}
