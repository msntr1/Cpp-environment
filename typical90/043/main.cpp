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
  ll rs, rt, cs, ct;
  cin >> rs >> cs >> rt >> ct;
  rs--, rt--, cs--, ct--;
  vector<string> S(H);
  REP (i, H) cin >> S[i];

  vector<vector<vector<ll>>> dist(H, vector<vector<ll>>(W,vector<ll>(5, -1))); //dist[i][j][k]: 縦i横j向きkの方向転換の回数
  queue<tuple<ll, ll, ll>> Q; // 位置と方向(0:停止　1:右　以降時計回り)
  const vector<ll> dy = {0, 1, 0, -1};
  const vector<ll> dx = {1, 0, -1, 0};

	Q.push({rs, cs, 0});
	dist[rs][cs][0] = 0;
	while (!Q.empty()) {
		auto pos = Q.front(); Q.pop();
		for (ll i = 1; i <= 4; i++) {
      ll y, x, di;
      tie(y, x, di) = pos;
			ll toy = dy[i-1]+y, tox = dx[i-1]+x;
      if (toy < 0 || toy >= H || tox < 0 || tox >= W) continue;
      if (S[toy][tox] == '#') continue;

      ll todist = dist[y][x][di];
      if (di != 0 && di != i) todist++;
			if (dist[toy][tox][i] == -1 || todist < dist[toy][tox][i]) {
        dist[toy][tox][i] = todist;
				Q.push(make_tuple(toy, tox, i));
			}
		}
	}
	// 出力
  ll ans = infl;
	REP3 (i, 1, 5) {
    if (dist[rt][ct][i]==-1) continue;
    chmin(ans, dist[rt][ct][i]);
  }
  cout << ans << endl;
	return 0;
}
