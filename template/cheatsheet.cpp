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

ll x, y;


//チートシート　忘れがちな構文まとめ

// デバッグで困ったら見るページ↓
// https://qiita.com/e869120/items/8be6521e72025d7b2a13

signed main () {
  ll key, value, a, b, N, M;

  /*  
      ～型変換・フォーマット～
  */

  // 文字列をint型に変換 （同様の機能にatoiがあるが、こちらはCの関数であり直接文字列を渡せず、エラーも検知しない。）
  string Str; int num = stoi(Str);

  // 数値を文字列に変換
  Str = to_string(num);

  // ASCII値を文字に変換
  ll ascii = 'a'; cout << char(ascii) << endl;

  // 文字を数値に変換
  char c = '5'; ll a = c - '0'; // c = 5

  // 大文字小文字の変換(文字列)
  // ::tolowerは、[](char const &c) {return std::tolower(c);}の短縮形
  transform(all(Str), Str.begin(), ::tolower);
  // もしくは
  for (auto &x: Str) x = tolower(x);

  // modが固定されていない時のmodint
  using mint = modint;
  ll mod;
  cin >> mod;
  mint::set_mod(mod);

  // 配列を1ずつ増えていく値で埋める
  vector<ll> vec(9);
  iota(all(vec), 1);


  // 桁揃え・ゼロ埋め 2パターン
  char buf[13]; a = 1; b = 2;
  sprintf(buf, "%6d", a);   //  "     1"
  sprintf(buf, "%-6d", b);  // "2     "
  sprintf(buf, "%06d%06d", a, b); // "000001000002"

  cout << setfill('0') << right << setw(4) << 12; // "0012"
  cout << setfill('0') << left  << setw(4) << 12; // "1200"
  cout << setfill(' '); // ゼロ埋め・解除（デフォルトに戻す）
  
  // 浮動小数点の制度を設定
  double d = 1.1234567899;
  cout << d << endl; // 1.12345
  cout << setprecision(9) << d << endl; // 1.12345678
  cout << fixed << setprecision(9) << d << endl; // 1.123456789 小数点以下9桁に固定 四捨五入？される
  cout << defaultfloat; // 書式を初期状態に戻す


  /*  
      ～配列～
  */
 

  // 配列のサイズ変更 二種類ある
  vector<ll> vec(1,0); vec.resize(2,1); //要素を2に変更　初期値1 {0, 1}
  vec.assign(3, 10); //要素数を3に変更してすべて10で上書き {10, 10, 10}

  // 比較関数を使ったソート
  sort(all(vec), [](auto a, auto b){
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  });

  // 配列の重複を消す
  vec.erase(unique(all(vec)), vec.end());

  // 順列の全列挙
  sort(all(vec));
  do {
    // 順列に対する処理
  } while (next_permutation(all(vec)));

  // 前の順列の生成　sort()と同じように実行するだけで配列自体を操作できる
  prev_permutation(all(vec));

  //
  // 連想配列の宣言
  map<ll, ll> MAP;
  // 	  記法　　　    　操作  　 計算量
  MAP[key] = value; //値の追加  O(logN)  keyに対応するvalueが存在しない場合値が追加される
  MAP.erase(key);  // 値の削除  O(logN)
  MAP.at(key); // 値へのアクセス O(logN)
  MAP.count(key); // 所属判定	  O(logN)
  MAP.size();    // 要素数の取得	O(1)
  // 連想配列の全要素を取り出す
  for (const auto& [k, v] : MAP) {
    // 処理
  }

  // タプル型の宣言、要素へのアクセス
  tuple<ll, ll, ll> t(0, 1, 2);
  cout << get<1>(t) << endl; // 1


  /*  
      ～関数～
  */

  // ラムダ式による再帰関数 普通のラムダ式はauto型に代入して良い
  //　ll型を返す場合->で型を指定しないとなぜかエラーが出る。
  function<ll(ll)> sum = [&](ll n) -> ll {
    if (n == 0) return 0;
    else return n + sum(n - 1);
  };

  // 再帰全探索
  function<ll(vector<ll>)> dfs = [&](vector<ll> A) -> ll {
    // ベースケース
    if (A.size() == N) {
      // 処理
      return 0;
    }

    REP (add, M) {
      A.push_back(add); // バックトラック
      dfs(A);
      A.pop_back();
    }
    return 0;
  };


  /*  
      ～計算～
  */

  // 除算（切り上げ）
  cout << (a + b - 1) / b << endl;

  // 最大公約数,最小公倍数を求める関数
  gcd(a, b); lcm(a, b);

  // 自分で計算する方法（ユークリッドの互除法）
  // long long gcd(long long a, long long b) {
  //   if (b == 0) {
  //       return a;
  //   } else {
  //       return gcd(b, a % b);
  //   }
  // };
  // /*  lcm (a, b) : 2整数版
  //     入力：整数 a, b
  //     出力：aとbの最小公倍数
  // */
  // long long lcm(long long a, long long b) {
  //     long long d = gcd(a, b);
  //     return a / d * b;
  // };

  // 数値nのそれぞれの桁の合計
  auto f = [&] (ll n) -> ll {
    ll ret = 0;
    while (n > 0) {
      ret += n % 10;
      n /= 10;
    }
    return ret;
  };

  // xのi+1桁目のbitをとる
  #define bit(x,i) (((x)>>(i))&1)



  // 1～Nの約数全列挙　O(NlogN) (調和級数)
  ll N;
  vector<vector<ll>> D(N+1); //divisor
  for(ll i=1;i<=N;i++){
    for(ll j=i;j<=N;j+=i) D[j].push_back(i);
  }
}

// エラトステネスのふるい（素数全列挙）
vector<bool> Eratosthenes(ll N) {
  // テーブル
  vector<bool> isprime(N+1, true);
  // 1 は予めふるい落としておく
  isprime[1] = false;
  // ふるい
  for (ll p = 2; p <= N; ++p) {
      // すでに合成数であるものはスキップする
      if (!isprime[p]) continue;

      // p 以外の p の倍数から素数ラベルを剥奪
      for (ll q = p * 2; q <= N; q += p) {
          isprime[q] = false;
      }
  }
  // 1 以上 N 以下の整数が素数かどうか
  return isprime;
}

// 素因数分解　(素因数,指数)のペア型配列を返す
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}



  /*  
      ～その他頻出処理～
  */


// 8方向の近傍座標指定用定数
const vector<ll> dx{-1, 0, 1, -1, 1, -1, 0, 1};
const vector<ll> dy{-1, -1, -1, 0, 0, 1, 1, 1};

// 4方向の近傍座標指定用定数
const vector<ll> dx{1, 0, -1, 0};
const vector<ll> dy{0, 1, 0, -1};

// // ループで近傍座標指定
// REP3(dx, -1, 2) REP3(dy, -1, 2) {
//   if (dx == 0 and dy == 0) continue;
//   ll xx = x + dx;
//   ll yy = y + dy;
// }

// 図形の90°回転
ll sz = 4; // 図形のサイズ
void rotate(vector<string>& v) {
  vector<string> w = v;
  REP(i, sz) REP(j, sz) w[(sz-1) - j][i] = v[i][j];
  v = w;
  return;
}


// めぐる式二分探索
vector<ll> a = {};
// index が条件を満たすかどうか
bool isOK(ll index, ll key) {
  if (a[index] >= key) return true;
  else return false;
}
// 汎用的な二分探索のテンプレ
long long binary_search(ll key) {
  ll ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
  ll ok = (ll)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

  /* ok と ng のどちらが大きいかわからないことを考慮 */
  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (isOK(mid, key)) ok = mid;
    else ng = mid;
  }
  return ok;
}


// 三分探索
// f(n)を計算して返す
long long func(ll n) {
  //処理
  return 0;
}
pair<long long, long long> ternary_search(ll lim) {
  ll l = 0;
  ll r = lim;
  /* 幅が3以上なら三分探索可能 */
  while (r - l >= 3) {
    ll m1 = (l*2 + r) / 3;
    ll m2 = (l + r*2) / 3;

    if (func(m1) > func(m2)) l = m1;
    else r = m2;
  }
  return {l, r};
}
signed main() {
  pair<ll, ll> m = ternary_search(1e18);
  ll ans = infl;
  for (ll i = m.first; i <= m.second; i++) {
    chmin(ans, func(i));
  }
  cout<< setprecision(10) << ans << endl;
}


// 全連結成分探索DFS
signed main() {
	// 入力
  ll N, M; // N頂点M辺のグラフ
	cin >> N >> M;
  vector<vector<ll>> G(N+1); // Graph隣接リスト
  vector<bool> visited(N+1, false);
	for (ll i = 1; i <= M; i++) {
    ll x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
  function<ll(ll)> dfs = [&](ll n) { // n は現在位置
	  visited[n] = true;
	  for (auto to: G[n]) {
		  if (visited[to] == false) dfs(to);
	  }
	  return 0;
  };
	// 全頂点で深さ優先探索
	for (ll i = 1; i <= N; i++) {
    if (visited[i] == false) {
      dfs(i);
    }
  }
}


// 距離を求めるBFS
signed main() {
	// 入力
  ll N, M;
	cin >> N >> M;
  vector<vector<ll>> G(N+1);
	//（dist[i]=-1 で初期化していることに注意）
  vector<ll> x(M+1), y(M+1), dist(N+1, -1);
  queue<ll> Q;
	for (ll i = 1; i <= M; i++) {
		cin >> x[i] >> y[i];
		G[x[i]].push_back(y[i]);
		G[y[i]].push_back(x[i]);
	}
	Q.push(1);
	dist[1] = 0;
	while (!Q.empty()) {
		ll pos = Q.front(); Q.pop();
		for (ll i = 0; i < G[pos].size(); i++) {
			ll to = G[pos][i];
			if (dist[to] == -1) {
				dist[to] = dist[pos] + 1;
				Q.push(to);
			}
		}
	}
	// 出力
	for (ll i = 1; i <= N; i++) cout << dist[i] << " ";
  cout << endl;
	return 0;
}


// ダイクストラ法 (正の重み付きグラフで頂点1から各頂点の距離を調べる)
signed main() {
  ll N, M; // N頂点M辺
  cin >> N >> M;
  // 目的地と距離のペア隣接グラフ
  vector<vector<pair<ll, ll>>> G(N+1);
  for (ll i = 0; i < M; i++) {
    ll a,b,c;
    cin >> a >> b >> c;
    G[a].push_back(make_pair(b, c));
    G[b].push_back(make_pair(a, c));
  }
  // 頂点1からの距離,頂点番号のペアで昇順優先度付きキュー
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
  vector<ll> cur(N+1, infl);
  vector<bool> kakutei(N+1, false);
  cur[1] = 0;
  Q.push(make_pair(cur[1], 1));
  // ダイクストラ法
  while (!Q.empty()) {
    ll pos = Q.top().second; Q.pop();
    if (kakutei[pos] == true) continue;
    kakutei[pos] = true;
    for (ll i = 0; i < G[pos].size(); i++) {
      ll nex = G[pos][i].first;
      ll cost = G[pos][i].second;
      if (cur[nex] > cur[pos] + cost) {
        cur[nex] = cur[pos] + cost;
        Q.push(make_pair(cur[nex], nex));
      }
    }
  }
  //　答えを出力
  for (ll i = 1; i <= N; i++) {
    if (cur[i] == infl) cout << "-1" << endl;
    else cout << cur[i] << endl;
  }
}

// Nが大きいとエラーを吐くのでacl推奨
// UnionFind
class UnionFind {
  public:
  ll par[200009]; 
  ll siz[200009];
  void init(ll N) {
    for (ll i = 1; i <= N; i++) par[i] = -1;
    for (ll i = 1; i <= N; i++) siz[i] = 1;
  }
  ll root(ll x) {
    while (true) {
      if (par[x] == -1) break;
      x = par[x];
    }
    return x;
  }
  void unite(ll u, ll v) {
    ll RootU = root(u);
    ll RootV = root(v);
    if (RootU == RootV) return;
    if (siz[RootU] < siz[RootV]) {
      par[RootU] = RootV;
      siz[RootV] += siz[RootU];
    }
    else {
      par[RootV] = RootU;
      siz[RootU] += siz[RootV];
    }
  }
  bool same(ll u, ll v) {
    if (root(u) == root(v)) return true;
    return false;
  }
};
signed main() {
  ll N; // N頂点で初期化
  cin >> N;
  UnionFind UF;
  UF.init(N);
}

// BFSトポロジカルソート　（DFSの帰りがけ順で十分な場合が多い）
vector<int> topological_sort(vector<vector<int>> graph) {
	int n = graph.size();
	vector<int> indegree(n);
	for (int i = 0; i < n; i++) for (int j : graph[i]) indegree[j]++;
	vector<int> res;
	queue<int> que;
	for (int i = 0; i < n; i++) if (indegree[i] == 0) que.push(i);
	while (!que.empty()) {
		int ver = que.front(); que.pop();
		res.push_back(ver);
		for (int i : graph[ver]) {
			indegree[i]--;
			if (indegree[i] == 0) que.push(i);
		}
	}
	return res;
}


// nCr組み合わせ計算 O(n)
mint ncr(ll n, ll r) {
  mint a = 1;
  for (ll i = 1; i <= n; i++) a *= i;
  mint b = 1;
  for (ll i = 1; i <= r; i++) b *= i;
  for (ll i = 1; i <= n-r; i++) b *= i;
  return a / b;
}


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


// 座標上の三角形内部に点があるか判定
bool insideTriangle (double p0x, double p0y, double p1x, double p1y, 
                    double p2x, double p2y, double px, double py) {
  //(p0x, p0y),(p1x, p1y),(p2x, p2y)の三角形
  //(px, py)が判定したい点
  double Area = 0.5 *(-p1y*p2x + p0y*(-p1x + p2x) + p0x*(p1y - p2y) + p1x*p2y);
  double s = 1/(2*Area)*(p0y*p2x - p0x*p2y + (p2y - p0y)*px + (p0x - p2x)*py);
  double t = 1/(2*Area)*(p0x*p1y - p0y*p1x + (p0y - p1y)*px + (p1x - p0x)*py);

  if(0 < s && s < 1 && 0 < t && t < 1 && 0<1-s-t && 1-s-t<1){
      return true; //Inside Triangle
  }else{
      return false;
  };
}


// 凸包生成
vector<pair<long long,long long>> convex_hull(vector<pair<long long,long long>> P){
// Copyright (c) 2023 0214sh7
// https://github.com/0214sh7/library/
if(P.size()<=2){
    return P;
}
vector<pair<long long,long long>> H,L,R;
sort(P.begin(),P.end());
//下半分
for(int i=0;i<P.size();i++){
    int j=L.size();
    while(j>=2 && (L[j-1].first-L[j-2].first)*(P[i].second-L[j-2].second)<=(L[j-1].second-L[j-2].second)*(P[i].first-L[j-2].first)){
        L.pop_back();
        j--;
    }
    L.push_back(P[i]);
}
//上半分
for(int i=P.size()-1;i>=0;i--){
    int j=H.size();
    while(j>=2 && (H[j-1].first-H[j-2].first)*(P[i].second-H[j-2].second)<=(H[j-1].second-H[j-2].second)*(P[i].first-H[j-2].first)){
        H.pop_back();
        j--;
    }
    H.push_back(P[i]);
}
R=L;
for(int i=1;i<H.size()-1;i++){
    R.push_back(H[i]);
}
return R;
}
// 使用例
signed main () {
  vector<pair<long long,long long>> P,Q;
  P.push_back({0,0});
  P.push_back({2,0});
  P.push_back({1,1});
  P.push_back({0,2});
  P.push_back({2,2});
  Q = convex_hull(P);
  for(ll i=0;i<Q.size();i++){
      cout << Q[i].first << " " << Q[i].second << endl;
  }
}

// ローリングハッシュ
signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  // 入力
  ll N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<ll> a(Q+1), b(Q+1), c(Q+1), d(Q+1);
  REP3 (i, 1, Q+1) cin >> a[i] >> b[i] >> c[i] >> d[i];
  // ハッシュ値を計算するための変数
  ll mod = 2147483647; // 値が大きくなるので余りをとる　modが大きいほど衝突の可能性が低い
  mint::set_mod(mod);
  vector<mint> T(N+1), H(N+1), Power100(N+1);  // T[i]:i文字目のハッシュ値 H:[i]1からiのハッシュ値
  // 文字を数値に変換
  REP3 (i, 1, N+1) T[i] = (S[i-1]-'a') + 1;
  // 100のn乗を前計算する
  Power100[0] = 1;
  REP3 (i, 1, N+1) Power100[i] = 100LL * Power100[i-1];
  // 1からi文字目までのハッシュを計算する
  H[0] = 0;
  REP3 (i, 1, N+1) H[i] = (100LL * H[i-1] + T[i]);
  // LからRまでのハッシュ計算
  auto Hash_value = [&](ll l, ll r) -> ll {
    ll val = (H[r] - (H[l-1] * Power100[r-l+1])).val();
    if (val < 0) val += mod;
    return val;
  };
  // クエリに答える
  REP3 (i, 1, Q+1) {
    ll Hash1 = Hash_value(a[i], b[i]);
    ll Hash2 = Hash_value(c[i], d[i]);
    if (Hash1 == Hash2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

