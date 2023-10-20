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
  vector<vector<ll>> A(N+1, vector<ll>(N+1));
  REP3 (i, 1, N+1) REP3 (j, 1, N+1) cin >> A[i][j];
  ll M;
  cin >> M;
  vector<vector<bool>> G(N+1, vector<bool>(N+1, true)); // Graph隣接行列
  vector<bool> visited(N+1, false);
	for (ll i = 1; i <= M; i++) {
    ll x, y;
		cin >> x >> y;
		G[x][y] = false;
		G[y][x] = false;
	}
  ll sum = 0, ans = infl;

  function<ll(ll, ll)> dfs = [&](ll n, ll x) { // n は選手 x は区間
	  visited[n] = true;
    sum += A[n][x];
    if (x == N) chmin(ans, sum);
	  REP3 (to, 1, N+1) {
		  if (visited[to] == false && G[n][to] == true) dfs(to, x+1);
	  }
    visited[n] = false;
    sum -= A[n][x];
	  return 0;
  };
	// 全頂点で深さ優先探索
	for (ll i = 1; i <= N; i++) {
    dfs(i, 1);
  }
  if (ans == infl) cout << -1 << endl;
  else cout << ans << endl;
}
