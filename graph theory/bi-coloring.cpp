#include<bits/stdc++.h>
#define  MX      100005
#define  ff      first
#define  ss      second
#define  pb      push_back
#define  int     long long
#define  PII     pair<int,int>
#define  all(v)  v.begin(),v.end()
#define  pi      acos(-1)
#define  mod     1000000007
using namespace std;
const int N = 5e5 + 5;
vector<int>adj[N];
int color[N];
bool vis[N];

bool dfs(int node , int c) {
	vis[node] = 1;
	color[node] = c;
	for (int child : adj[node]) {
		if (!vis[child]) {
			if (!dfs(child, c ^ 1))return false;
		}
		else {
			if (color[node] == color[child])return false;
		}
	}
	return true;
}

void solve(int t) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			if (!dfs(i, 0)) {
				cout << "IMPOSSIBLE" << endl;
				return;
			}
		}
	}
	for (int i = 1; i <= n; i++)cout << color[i] << " ";
	cout << endl;
}

signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

