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
  vector<ll> X(N), Y(N);
  REP(i, N) cin >> X[i] >> Y[i];
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }

  sort(all(X));
  sort(all(Y));
  
  ll distX = 0;
  ll distY = 0;
  REP3 (i, 1, N) {
    distX += X[i];
    distY += Y[i];
  }
  distX -= (X[0]*(N-1));
  distY -= (Y[0]*(N-1));
  ll ansX = distX;
  ll ansY = distY;

  REP3 (i, 1, N) {
    distX -= (X[i]-X[i-1])*(N-i);
    distX += (X[i]-X[i-1])*i;
    chmin(ansX, distX);

    distY -= (Y[i]-Y[i-1])*(N-i);
    distY += (Y[i]-Y[i-1])*i;
    chmin(ansY, distY);
  }

  cout << (ansX+ansY) << endl;
}
