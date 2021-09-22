// Problem: Building Roads
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1666
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// Problem: Counting Rooms
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1192
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
#define vii				vector<vi>
#define all(c) 			(c).begin(),(c).end()
#define mii             map<int,int>
#define max(a,b)		a>=b?a:b
#define min(a,b)		a<=b?a:b
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

const int N=100005;
vector<int> g[N];
vector<bool> visit(N,false);
int dir1[]={0,0,-1,1};
int dir2[]={1,-1,0,0};
int n,m;

void dfs(int i){
	
	visit[i]=true;
	for(auto z: g[i]){
		if(visit[z])continue;

		dfs(z);
	}
}
void solve(){
	
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	
	int ans=0;
	vector<int> st_node;
	for(int i=1;i<=n;i++){
		if(visit[i])continue;
		ans++;
		st_node.pb(i);
		dfs(i);
	}
	ans--;	
	cout<<ans<<endl;
	for(int i=1;i<st_node.size();i++){
		cout<<st_node[i-1]<<" "<<st_node[i]<<endl;
	}
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
