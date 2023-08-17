//BISMILLAHIR RAHMANIR RAHEEM
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
const int N = 1e5 + 5;

vector<PII>adj[N];

void dijkstra(int src) {
	vector<int>vis(N, 0);
	vector<int>dis(N, INF);

	set<PII>st;
	st.insert({0, src});
	dis[src] = 0;
	while (st.size() > 0) {
		auto node = *st.begin();
		int v = node.ss;
		int dist = node.ff;
		st.erase(st.begin());
		if (vis[v])continue;
		vis[v] = 1;
		for (auto child : adj[v]) {
			int ch_v = child.ss;
			int wt = child.ff;
			if (dis[v] + wt < dis[ch_v]) {
				dis[ch_v] = dis[v] + wt;
				st.insert({dis[ch_v], ch_v});
			}
		}
	}
}

void solve(int t) {
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, wt; cin >> x >> y >> wt;
		adj[x].pb({y, wt});
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}

	return 0;
}

