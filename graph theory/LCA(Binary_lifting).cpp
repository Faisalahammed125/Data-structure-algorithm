//BISMILLAHIR RAHMANIR RAHEEM
//problem link: https://cses.fi/problemset/task/1688
#include<bits/stdc++.h>
#define  MX           100005
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  int          long long
#define  endl         "\n"
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  pi           acos(-1)
#define  mod          1000000007
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;
const int N = 2e5 + 1;
const int LOG = 18;

vector<int>child[N];
int up[N][LOG];  // up[v][j] is 2^j-th ancestor of v
int depth[N];

//dfs is used to calculate the level and 2^j th anchestor of a node
void dfs(int node) {
    for (int x : child[node]) {
        depth[x] = depth[node] + 1;
        up[x][0] = node;  //node is a parent of x
        for (int j = 1; j < LOG; j++) {
            up[x][j] = up[up[x][j - 1]][j - 1];
        }
        dfs(x);
    }
}

int get_lca(int a, int b) {
    if (depth[a] < depth[b])
        swap(a, b);
    //Get same depth
    int k = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            a = up[a][i];
        }
    }
    //if b is a ancestor of a then a==b
    if (a == b) {
        return a;
    }
    //now move both a and b with power of two
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void solve(int t) {
    int n, q; cin >> n >> q;
    child[0].pb(1);
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        child[x].pb(i);
    }
    dfs(0);
    while (q--) {
        int a, b; cin >> a >> b;
        cout << get_lca(a, b) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}