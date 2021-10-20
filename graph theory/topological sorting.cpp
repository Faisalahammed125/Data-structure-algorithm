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
const int N=5e5+5;

vector<int>adj[N];
bool vis[N];
vector<int>res;

void dfs(int node){
	vis[node]=1;
	for(int child : adj[node])
		if(!vis[child])
			dfs(child);
	res.pb(node);
}

void solve(int t){
    int node,edge;
    cin>>node>>edge;

    for(int i=0;i<edge;i++){
    	int x,y;
    	cin>>x>>y;
    	adj[x].pb(y);
    }
    for(int i=1;i<=node;i++)
    	if(!vis[i])
    		dfs(i);
    reverse(all(res));
    for(int x : res)cout<<x<<" ";
    cout<<endl;
}

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int T=1;
   //cin>>T;
   for(int t=1;t<=T;t++){
        solve(t);
   }

   return 0;
}

