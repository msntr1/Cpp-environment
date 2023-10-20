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


class SegmentTree {
    public:
    vector<ll> dat;
    ll siz = 1;

    void init(ll N) {
      siz = 1;
      while (siz < N) {
        siz *= 2;
      }
      dat.resize(siz*2);
      REP (i, siz*2) dat[i] = 0;
    }

    void update(ll pos, ll x) {
      pos = pos + siz - 1;
      dat[pos] = x;
      while (pos >= 2) {
        pos /= 2;
        dat[pos] = min(dat[pos*2], dat[pos*2+1]);
      }
    }

    ll query(ll l, ll r, ll a, ll b, ll u) {
      if (r <= a || l >= b) return infl;
      if (l <= a && r >= b) return dat[u];
      ll m = (a+b) / 2;
      ll AnswerL = query(l, r, a, m, u*2);
      ll AnswerR = query(l, r, m, b, u*2+1);
      return min(AnswerL, AnswerR);
    }
  };


signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // 入力
  ll N, L, R;
  cin >> N >> L >> R;
  vector<ll> X(N);
  REP (i, N) cin >> X[i];

  vector<ll> DP(N);
  DP[0] = 0;
  SegmentTree Z;
  Z.init(N);

  REP3 (i, 1, N) {
    ll l = lower_bound(all(X), X[i]-R) - X.begin();
    ll r = upper_bound(all(X), X[i]-L) - X.begin() - 1;
    DP[i] = Z.query(l+1, r+2, 1, Z.siz+1, 1) + 1;
    Z.update(i+1, DP[i]);
  }

  cout << DP[N-1] << endl;
}
