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
  ll H, W;
  cin >> H >> W;
  vector<string> C(H);
  REP (i, H) cin >> C[i];
  ll N = H * W;
  vector<bool> visited(N, false);
  const vector<ll> d = {1, W, -1, -W};
  ll cnt = 0, ans = -1;
  function<ll(ll, ll)> dfs = [&](ll n, ll s) { // n は現在位置 sはスタート
	  visited[n] = true;
    cnt++;
	  REP (i, 4) {
      if ((i == 0 && n%W == W-1) || (i == 2 && n%W == 0)) continue;
      ll to = n + d[i];
      if (to >= N || to < 0) continue;
		  if (visited[to] == false && C[to/W][to%W] != '#') dfs(to, s);
      if (to == s && cnt > 2) chmax(ans, cnt);
	  }
    visited[n] = false;
    cnt--;
	  return 0;
  };
	// 全頂点で深さ優先探索
	for (ll i = 0; i < N; i++) {
    if (C[i/W][i%W] != '#') {
      dfs(i, i);
    }
  }

  cout << ans << endl;
}
