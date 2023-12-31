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
typedef long long ll; typedef unsigned long long ull;
#define int ll
const ll infl = 1LL << 60;
#define REP(i,n) for (ll i = 0; (i) < (ll)(n); ++ (i))
#define REP3(i,m,n) for (ll i = (m); (i) < (ll)(n); ++ (i))
#define REP_R(i,n) for (ll i = (ll)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i,m,n) for (ll i = (ll)(n) - 1; (i) >= (ll)(m); -- (i))
#define all(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
#define bit(x,i) (((x)>>(i))&1)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }


void random_generate(ll N, vector<ll> &A, vector<ll> &B) {
  // ここでランダム生成をする。例えば次のような感じ。
  // for (ll i = 0; i < N; i++) A[i] = rand() % 10 + 1;
  // for (ll i = 0; i < N; i++) B[i] = rand() % 10 + 1;
}

ll solve(ll N, vector<ll> A, vector<ll> B) {
  // ここに自分のプログラムを書き、自分の答えを返す。
}

ll solve_Jury(ll N, vector<ll> A, vector<ll> B) {
  // ここに「遅いが正しいプログラム」を書き、正しい（と想定される）答えを返す
  return -infl;
}


signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // ランダムテスト
  for (ll t = 1; t <= 1000; t++) {
        ll N = 8; // 入力データのサイズ（適当に決めて良い)
        vector<ll> A(N), B(N); // プログラムで使用する変数
        random_generate(N, A, B);
        ll J1 = solve(N, A, B);
        ll J2 = solve_Jury(N, A, B);
        if (J1 != J2) {
            cout << "Wrong Answer on Test #" << t << endl;
            // テストケースを出力
            for (ll i = 0; i < N; i++) {cout << A[i]; (i<N-1?cout << " ":cout << endl);}
            for (ll i = 0; i < N; i++) {cout << B[i]; (i<N-1?cout << " ":cout << endl);}
            cout << "Jury = " << J2 << ", Output = " << J1 << endl;
            return 0;
        }
    }
    cout << "Yay!" << endl;
    return 0;
}
