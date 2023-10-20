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

vector<bool> visited(4000009, false);
// // UnionFind
// class UnionFind {
//   public:
//   ll par[4000009];
//   ll siz[4000009];
//   void init(ll N) {
//     for (ll i = 1; i <= N; i++) par[i] = -1;
//     for (ll i = 1; i <= N; i++) siz[i] = 1;
//   }
//   ll root(ll x) {
//     while (true) {
//       if (par[x] == -1) break;
//       x = par[x];
//     }
//     return x;
//   }
//   void unite(ll u, ll v) {
//     ll RootU = root(u);
//     ll RootV = root(v);
//     if (RootU == RootV) return;
//     if (siz[RootU] < siz[RootV]) {
//       par[RootU] = RootV;
//       siz[RootV] += siz[RootU];
//     }
//     else {
//       par[RootV] = RootU;
//       siz[RootU] += siz[RootV];
//     }
//   }
//   bool same(ll u, ll v) {
//     if (root(u) == root(v)) return true;
//     return false;
//   }
// };


signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // 入力
  
  ll H, W;
  cin >> H >> W;
  ll N = H*W; // N頂点で初期化
  dsu d(N);


  // 4方向の近傍座標指定用定数
  const vector<int> dx{1, W, -1, -W};
  ll Q;
  cin >> Q;
  REP (i, Q) {
    ll q;
    cin >> q;
    if (q == 1) {
      ll r, c;
      cin >> r >> c;
      ll pos = c + (r-1)*W -1;
      visited[pos] = true;
      REP (i, 4) {
        if ((i==0 && pos%W==W-1) || (i==2 && pos%W==0)) continue;
        ll to = pos + dx[i];
        if (to >= 0 && to < N && visited[to] == true) d.merge(pos, to);
      }
    }
    if (q == 2) {
      ll ra, ca, rb, cb;
      cin >> ra >> ca >> rb >> cb;
      ll posA = ca + (ra-1)*W -1;
      ll posB = cb + (rb-1)*W -1;
      if (visited[posA] == true && visited[posB] == true&& d.same(posA, posB)) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}
