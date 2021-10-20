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
int indeg[N];
vector<int>res;
int node,edge;

void Kahn()
{
   queue<int> q;

   for (int i = 1; i <= node; i++)
      if (indeg[i] == 0)
         q.push(i);

   while (!q.empty()) {
      int par = q.front();
      res.pb(par);
      q.pop();

      for (int child : adj[par]) {
         indeg[child]--;
         if (indeg[child] == 0)
            q.push(child);
      }
   }
}

void solve(int t){

    cin>>node>>edge;

    for(int i=0;i<edge;i++){
    	int x,y;
    	cin>>x>>y;
    	adj[x].pb(y);
        indeg[y]++;
    }
    Kahn();
    cout << "Topological order:\n";
    for (int x : res)
      cout << x << " ";
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

