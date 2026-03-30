// Problem =
//

// ================= COMPETITIVE PROGRAMMING TEMPLATE =================
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define all(x) (x).begin(), (x).end()
using namespace std;

// =================== CONSTANTS & TYPES ===================
using ld = long double;
const int INF = 1e9;
const ld EPS = 1e-9;
const int MOD = 1e9 + 7;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vc = vector<char>;

using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<ll>>;
using vvb = vector<vector<bool>>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K> using uset = unordered_set<K>;

// =================== MACROS ===================
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define uniq(x) x.erase(unique(all(x)), x.end())
#define endl '\n'
#define EACH(x, a) for (auto &x : a)
#define rep(i, a, b) for (ll i = (a); i <= (b); i++)
#define per(i, b, a) for (ll i = (b); i >= a; i--)

// =================== FAST IO ===================
void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

// =================== DEBUG ===================
#ifdef LOCAL
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  for (size_t i = 0; i < v.size(); i++)
    os << v[i] << (i + 1 == v.size() ? "" : ", ");
  return os << "}";
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{";
  for (auto it = s.begin(); it != s.end(); ++it)
    os << *it << (next(it) == s.end() ? "" : ", ");
  return os << "}";
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &s) {
  os << "{";
  for (auto it = s.begin(); it != s.end(); ++it)
    os << *it << (next(it) == s.end() ? "" : ", ");
  return os << "}";
}
template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << "{";
  for (auto it = m.begin(); it != m.end(); ++it)
    os << it->first << ": " << it->second << (next(it) == m.end() ? "" : ", ");
  return os << "}";
}
template <typename K, typename V>
ostream &operator<<(ostream &os, const unordered_map<K, V> &m) {
  os << "{";
  for (auto it = m.begin(); it != m.end(); ++it)
    os << it->first << ": " << it->second << (next(it) == m.end() ? "" : ", ");
  return os << "}";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  if (sizeof...(T))
    cerr << ",";
  debug_out(T...);
}
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// =================== VECTOR IO ===================
template <typename T> void read(vector<T> &a) {
  for (auto &x : a)
    cin >> x;
}
template <typename T> void print(const vector<T> &a) {
  for (auto &x : a)
    cout << x << ' ';
  cout << '\n';
}

// =================== SOLVE FUNCTION ===================

inline void solve() {
  int N;
  cin >> N;
  vvc grid(N, vc(N));
  rep(i, 0, N - 1) read(grid[i]);

  vvi dp(N, vi(N, 0));

  rep(i, 0, N - 1) rep(j, 0, N - 1) {
    if (grid[i][j] == '.') {
      if (i > 0)
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
      if (j > 0)
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
      if (i == 0 && j == 0)
        dp[i][j] = 1;
    } else
      dp[i][j] = 0;
  }

  cout << dp[N - 1][N - 1] % MOD << endl;
}

// =================== MAIN ===================
int main() {
  fast_io();
  int t = 1;
  // cin>>t;
  while (t--)
    solve();
  return 0;
}
