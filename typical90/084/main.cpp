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


// ランレングス圧縮　文字列を文字と個数の配列で表現
void rle(string s, vector<pair<char, ll>> &vec) {
  ll cnt = 1;
  for(ll i = 1; i < (ll)s.size(); i++){
    if(s[i] != s[i-1]){
      vec.push_back({s[i-1], cnt});
      cnt = 0;
    }
    cnt++;
  }
  vec.push_back({s.back(), cnt});
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // 入力
  ll N;
  string S;
  cin >> N >> S;
  ll ans = 0;
  ans += N*(N+1)/2;
  vector<pair<char, ll>> vec;
  rle(S, vec);
  REP (i, vec.size()) {
    ll x = vec[i].second;
    ans -= x*(x+1)/2;
  }

  cout << ans << endl;
}
