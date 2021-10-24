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

int power(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a; //here b is odd thats why a added to the result
		a=a*a;            // here b is even so, a= a*a;
		b>>=1;
	}
	return res;
}

void solve(int t){
    int a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
}

signed main()
{
   //ios::sync_with_stdio(0);
   //cin.tie(0);
   //cout.tie(0);
   int T=1;
   cin>>T;
   for(int t=1;t<=T;t++){
        solve(t);
   }

   return 0;
}

