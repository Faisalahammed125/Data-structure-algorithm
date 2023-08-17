//BISMILLAHIR RAHMANIR RAHEEM
//Problem link:https://cses.fi/problemset/task/1687/
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
const int N = 5e5 + 5;
vector<vector<int>>up;

void solve(int t) {
    int n, q; cin >> n >> q;
    vector<int>parent(n + 1, 0);
    rep(i, 2, n) {
        cin >> parent[i];
    }
    int l = ceil(log2(n));
    up.assign(l + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)up[0][i] = parent[i];
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }
    while (q--) {
        int node, k; cin >> node >> k;
        for (int i = 0; i <= l; i++) {
            if (k & (1 << i))
                node = up[i][node];
        }
        if (node)cout << node << endl;
        else cout << -1 << endl;
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