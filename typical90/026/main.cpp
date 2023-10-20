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
  REP (i, N-1) {
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<ll> visited(N+1, -1);
  ll sum = 0;

  function<ll(ll, ll)> dfs = [&](ll n, ll c) { // n は現在位置
	  visited[n] = c;
    if (c == 1) sum++;
	  for (auto to: G[n]) {
		  if (visited[to] == -1) dfs(to, c^1);
	  }
	  return 0;
  };

  dfs(1, 1);

  ll key = 0;
  if (sum >= N/2) key = 1;
  ll cnt = 0;
  REP3 (i, 1, N+1) {
    if (visited[i] == key){
      cnt++;
      cout << i << " ";
    }
    if (cnt == N/2) return 0;
  }
}
