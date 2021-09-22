// Problem: Shortest Routes I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1671
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
vector<pii> g[N];
vector<int> d(N,inf);
int n,m;
void dijkstra(int i){
	d[i]=0;
	
	set<pii> s;
	
	s.insert({d[i],i});
	
	while(s.size()>0){
		int u=s.begin()->second;
		s.erase(s.begin());
		for(auto z: g[u]){
			if(d[z.ff]> d[u] + z.ss){
				s.erase({d[z.ff],z.ff});
				d[z.ff]=d[u] + z.ss;
				s.insert({d[z.ff],z.ff});
			}
		}
	}
}
void solve(){
	cin>>n>>m;
	
	
	for0(i,m){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
		//flight is bi directional road
		//g[v].pb({u,w});
	}
	
	
	dijkstra(1);
	for(int i=1;i<=n;i++){
		cout<<d[i]<<" ";
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
