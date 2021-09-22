// Problem: Tree Matching
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1130
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define for0(i,n)       for (int i=0;i<(n);i++)
#define for1(i,n)       for (int i=1;i<=(n);i++)
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>

#define all(c) 			(c).begin(),(c).end()
#define mii             map<int,int>

#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=200005;

vector<int> tree[N];
int n,a,b;
vi dp1,dp2;
vector<vector<int>> g(N,vector<int>());
void dfs(int u, int p){
	for(auto z:g[u]){
		if(z==p)continue;
		
		dfs(z,u);
		dp2[u]+=max(dp1[z],dp2[z]);
		
	}
	
	for(auto z:g[u]){
		if(z==p)continue;
		dp1[u]=max(dp1[u],1+dp2[u]+dp2[z] -max(dp1[z],dp2[z]));
	}
}

void solve(){
	
	cin>>n;
	dp1 =vi(n);
	dp2 =vi(n);
	
	
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		//becoz of this , whatever be the root no problem.
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,0);
	cout<<max(dp1[0],dp2[0])<<endl;
	return ;
}
int32_t main()
{	
	FIO;
	
	int t=1;
	
	while(t--){
		solve();
	}
	return 0;
}
