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
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};
int n, m;

inline void solve() {
    cin >> n >> m ;
    vector<string> g(n);
    for(auto &i : g) cin >> i;

    vvi mdist(n , vi(m, INF));
    vvi dist(n, vi(m, -1));
    vvc par(n, vector<char>(m, 0));
    queue<pii> q;

    int sx = -1;
    int sy = -1;

    rep(i, 0, n-1) rep(j, 0, m-1){
        if(g[i][j] == 'M') {
            mdist[i][j] = 0;
            q.push({i, j});
        }
        if(g[i][j] == 'A'){
            sx = i;
            sy = j;
        }
    }

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        rep(k, 0, 3){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(g[nx][ny] == '#') continue;
            if(mdist[nx][ny] != INF) continue;

            mdist[nx][ny] = mdist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    q.push({sx, sy});
    dist[sx][sy] = 0;
    pii exit = {-1, -1};

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        if(x == 0 || y == 0 || x == n-1 || y == m-1){
            exit = {x,y};
            break;
        }

        rep(k , 0, 3){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(g[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1) continue;
            if(dist[x][y] + 1 >= mdist[nx][ny]) continue;

            dist[nx][ny] = dist[x][y] + 1;
            par[nx][ny] = dir[k];
            q.push({nx, ny});
        }
    }

    if(exit.first == -1){
        cout << "NO" << endl;
        return;
    }

    string path;
    auto [x,y] = exit;
    while(x != sx || y != sy){
        char d = par[x][y];
        path += d;
        if(d == 'U') x++;
        else if(d == 'D') x--;
        else if(d == 'L') y++;
        else if(d == 'R') y--;
    }

    reverse(all(path));
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
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
