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

int n,m ;
vector<string> grid;
vvi vis;
vector<vector<pii>> par;
vector<vector<char>> dir;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dc[] = {'U', 'D', 'L', 'R'};
int sx, sy, ex, ey;

inline void solve() {
    cin >> n >> m;
    grid.resize(n);
    vis.assign(n, vi(m, 0));
    par.assign(n, vector<pii>(m, {-1, -1}));
    dir.assign(n, vector<char>(m));

    rep(i, 0, n-1){
        cin >> grid[i];
        rep(j, 0, m-1){
            if(grid[i][j] == 'A'){
                sx = i; sy = j;
            }
            if(grid[i][j] == 'B'){
                ex = i; ey = j;
            }
        }
    }

    // BFS
    queue<pii> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        rep(k, 0, 3){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(0 <= nx && 0 <= ny && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny] != '#' ){
                vis[nx][ny] = 1;
                par[nx][ny] = {x,y};
                dir[nx][ny] = dc[k];
                q.push({nx, ny});
            }
        }
    }

    if(!vis[ex][ey]){
        cout << "NO" << endl;
        return;
    }

    string path;
    int x = ex;
    int y = ey;

    while(make_pair(x,y) != make_pair(sx, sy)){
        path += dir[x][y];
        auto [px, py] = par[x][y];
        x = px;
        y = py;
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
