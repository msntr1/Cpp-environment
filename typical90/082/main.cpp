#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
//using mint = modint;
using mint = modint1000000007;
//using mint = modint998244353;
typedef long long ll;
typedef unsigned long long ull;
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
  ull L, R;
  cin >> L >> R;
  L--;
  mint ans = 0;

  REP3 (i, 1, 20) {
    ull x = min(R, ull(pow(10,i))-1);
    ull y = max(L, ull(pow(10,i-1))-1);
    if (x <= y) continue;
    mint mx = x;
    mint my = y;
    mint dx = mx*(mx+1)/2;
    mint dy = my*(my+1)/2;
    ans += (dx-dy)*i;
  }

  cout << ans.val() << endl;
}
