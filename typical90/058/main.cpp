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
  ll N, K;
  cin >> N >> K;

  if (N == 0) {
    cout << 0 << endl;
    return 0;
  }

  vector<ll> A(100000, -1);
  A[N] = 0;

  auto f = [&] (ll n) -> ll {
    ll ret = 0;
    while (n > 0) {
      ret += n % 10;
      n /= 10;
    }
    return ret;
  };

  mint::set_mod(100000);
  mint cur = N;
  ll per = 0;
  REP3 (i, 1, 100001) {
    cur += f(cur.val());
    if (A[cur.val()] == -1) {
      A[cur.val()] = i;
    }
    else {
      K -= A[cur.val()];
      per = i - A[cur.val()];
      break;
    }
    if (i == K) {
      cout << cur.val() << endl;
      return 0;
    }
  }

  K = K % per;

  REP (i, K) {
    cur += f(cur.val());
  }

  cout << cur.val() << endl;
}
