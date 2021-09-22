// Problem: Company Queries I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1687
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
const int N=200005;
vector<int> g[N];
//binary lifting
// N x log(N)
int up[N][20];
int lvl[N];


void dfs(int src, int par=-1, int level=0){
	
	lvl[src]=level;
	for(auto z: g[src]){
		if(z==par)continue;

		dfs(z,src,level+1);
	}
}

void binary_lift(int src,int par){
	up[src][0]=par;
	for(int i=1;i<20;i++){
		if(up[src][i-1]!=-1)
			up[src][i]=up[up[src][i-1]][i-1];
		
		else
			up[src][i]=-1;
	}
	
	for(auto child : g[src]){
		if(child==par)continue;
		
		binary_lift(child,src);
	}
}

int lift_node(int node, int jump_required){
	
		for(int i=19;i>=0;i--){
			if(node==-1 or jump_required==0)
			break;
			
			if(jump_required>=(1<<i)){
				jump_required-= (1<<i);
				node = up[node][i];
			}
		}
		return node;
}

// int LCA(int u, int v){
	// if(lvl[u]<lvl[v])
	// swap(u,v);
// 	
	// u=lift_node(u,lvl[u]-lvl[v]);
// 	
	// int lo=0, hi=lvl[u];
// 	
	// while(lo!= hi){
		// int mid = (lo + hi)/2;
		// int x1= lift_node(u,mid);
		// int x2= lift_node(v,mid);
// 		
		// if(x1==x2)
		// hi=mid;
// 		
		// else
		// lo=mid+1;
	// }
	// return lift_node(u,lo);
// }

int LCA2(int u, int v){
	if(lvl[u]<lvl[v])
	swap(u,v);
	
	u=lift_node(u,lvl[u]-lvl[v]);
	
	if(u==v)
	return u;
	
	for(int i=19;i>=0;i--){
		if(up[u][i]!=up[v][i]){
			u=up[u][i];
			v=up[v][i];
		}
	}
	
	return lift_node(u,1);
}
void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		g[i].pb(x);
		g[x].pb(i);
	}
	dfs(1);
	binary_lift(1,-1);
	
	while(q--){
		int n1,n2;
		cin>>n1>>n2;
		cout<<LCA2(n1,n2)<<endl;
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