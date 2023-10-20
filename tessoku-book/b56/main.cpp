#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint;
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
  ll N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<ll> L(Q+1), R(Q+1);
  REP3 (i, 1, Q+1) cin >> L[i] >> R[i];
  // ハッシュ値を計算するための変数
  ll mod = 2147483647;
  mint::set_mod(mod);
  vector<mint> T(N+1), H(N+1), rH(N+2), Power100(N+1); // T[i]:i文字目のハッシュ値 H:[i]1からiのハッシュ値
  // 文字を数値に変換
  REP3 (i, 1, N+1) T[i] = (S[i-1]-'a') + 1;
  // 100のn乗を前計算する
  Power100[0] = 1;
  REP3 (i, 1, N+1) Power100[i] = 100LL * Power100[i-1];
  // 1からi文字目までのハッシュを計算する
  H[0] = 0;
  REP3 (i, 1, N+1) H[i] = (100LL * H[i-1] + T[i]);
  REP3R (i, 1, N+1) rH[i] = (100LL * rH[i+1] + T[i]);
  // LからRまでのハッシュ計算
  auto Hash_value = [&](ll l, ll r) -> ll {
    ll val;
    if (l < r) val = (H[r] - (H[l-1] * Power100[r-l+1])).val();
    else val = (rH[r] - (rH[l+1] * Power100[l-r+1])).val();
    if (val < 0) val += mod;
    return val;
  };
  // クエリに答える
  REP3 (i, 1, Q+1) {
    ll Hash1 = Hash_value(L[i], R[i]);
    ll Hash2 = Hash_value(R[i], L[i]);
    if (Hash1 == Hash2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
