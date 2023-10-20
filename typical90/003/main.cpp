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
  vector<vector<ll>> G(N+1);
  vector<ll> x(N), y(N), dist(N+1);
  queue<ll> Q;
	for (ll i = 1; i <= N-1; i++) {
		cin >> x[i] >> y[i];
		G[x[i]].push_back(y[i]);
		G[y[i]].push_back(x[i]);
	}

  ll d = 0, far = 0;
	//（dist[i]=-1 で初期化していることに注意）
	for (ll i = 1; i <= N; i++) dist[i] = -1;
	Q.push(1);
	dist[1] = 0;
	while (!Q.empty()) {
		ll pos = Q.front(); Q.pop();
		for (ll i = 0; i < G[pos].size(); i++) {
			ll to = G[pos][i];
			if (dist[to] == -1) {
				dist[to] = dist[pos] + 1;
        if (chmax(d, dist[to])) far = to;
				Q.push(to);
			}
		}
	}
  // bfs二回目
  ll ans = 0;
  for (ll i = 1; i <= N; i++) dist[i] = -1;
  Q.push(far);
  dist[far] = 0;
  while (!Q.empty()) {
		ll pos = Q.front(); Q.pop();
		for (ll i = 0; i < G[pos].size(); i++) {
			ll to = G[pos][i];
			if (dist[to] == -1) {
				dist[to] = dist[pos] + 1;
        chmax(ans, dist[to]);
				Q.push(to);
			}
		}
	}


	// 出力
  cout << ans + 1 << endl;
	return 0;
}
