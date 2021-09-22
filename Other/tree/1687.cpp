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

// int ans_query(int node, int jump_required){
// 	
	// if(node==-1 or jump_required==0)
	// return node;
// 	
	// for(int i=19;i>=0;i--){
		// if(jump_required>=(1<<i)){
			// return ans_query(up[node][i], jump_required-(1<<i));
		// }
	// }
// }
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

void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		g[i].pb(x);
		g[x].pb(i);
	}
	
	binary_lift(1,-1);
	
	while(q--){
		int node,level;
		cin>>node>>level;
		cout<<lift_node(node, level)<<endl;
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
