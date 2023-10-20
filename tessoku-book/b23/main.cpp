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
  vector<double> X(N+1), Y(N+1);
  REP3 (i, 1, N+1) cin >> X[i] >> Y[i];
  vector<vector<double>> DP((1<<N), vector<double>(N+1, infl));
  DP[0][1] = 0;
  REP (i, (1<<N)) REP3 (j, 1, N+1) {
    REP3 (k, 1, N+1) {
      if (j==k) continue;
      if (i&(1<<(k-1))>0) continue;
      double dis = sqrt((X[j]-X[k])*(X[j]-X[k])+(Y[j]-Y[k])*(Y[j]-Y[k]));
      ll to = i | (1<<(k-1));
      chmin(DP[to][k], DP[i][j] + dis);
    }
  }

  cout << fixed << setprecision(9) << DP[(1<<N)-1][1] << endl;
}
