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
  ll K;
  cin >> K;

  vector<ll> yaku;
  for (ll i = 1; i*i <= K; i++) {
    if (K%i == 0) {
      yaku.push_back(i);
      if (i*i != K) yaku.push_back(K/i);
    }
  }

  sort(all(yaku));
  ll ans = 0;
  REP (i, yaku.size()) REP3 (j, i, yaku.size()) {
    if (K%yaku[i] == 0 && K/yaku[i]%yaku[j] == 0 && K/yaku[i]/yaku[j] >= yaku[j]) ans++;
  }
  cout << ans << endl;
}
